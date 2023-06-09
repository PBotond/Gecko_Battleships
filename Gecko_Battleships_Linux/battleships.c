#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/select.h>
#include <poll.h>
#define _XOPEN_SOURCE
#include <time.h>

#include "battleships.h"

/*************
 * Debugging *
 *************/
#define CMDLINE_DBG true

uint32_t g_serial_speed = 9600;
uint32_t g_termio_speed = 0;
char g_serial_device[CFGSTR_SIZE] = "/dev/ttyACM0";
// char g_infile[FILENAME_SIZE] = "stdin";
char g_outfile[FILENAME_SIZE] = "game.log";

FILE *g_outfile_fp = NULL;

// Constants from /usr/include/asm-generic/termbits.h
// Constants are octal in termbits.h
struct BNUM_speed g_speed[] = {
	{50, B50},
	{75, B75},
	{110, B110},
	{134, B134},
	{150, B150},
	{200, B200},
	{300, B300},
	{600, B600},
	{1200, B1200},
	{1800, B1800},
	{2400, B2400},
	{4800, B4800},
	{9600, B9600},
	{19200, B19200},
	{38400, B38400},
	{57600, B57600},
	{115200, B115200},
	{230400, B230400},
	{460800, B460800},
	{500000, B500000},
	{576000, B576000},
	{921600, B921600},
	{1000000, B1000000},
	{1152000, B1152000},
	{1500000, B1500000},
	{2000000, B2000000},
	{2500000, B2500000},
	{3000000, B3000000},
	{3500000, B3500000},
	{4000000, B4000000},
	{0, 0} // Null termination, keep as the last element...
};

void exit_function(void)
{
	terminal_setup(true);
	fflush(g_outfile_fp);
}

bool set_g_speed(int speed)
{
	int i = 0;
	for (i = 0; g_speed[i].speed != speed; i++)
	{
		if (g_speed[i].speed == 0)
		{
			return false;
		}
	}
	g_termio_speed = g_speed[i].bnum;
	return true;
}

void print_messages(int message_type)
{
	switch (message_type)
	{
	case MESSAGE_INFO:
		printf(TERM_COLOR_BLUE "[INFO] " TERM_COLOR_DEFAULT);
		break;
	case MESSAGE_ERROR:
		perror(TERM_COLOR_RED "[ERROR] " TERM_COLOR_DEFAULT);
		break;
	case MESSAGE_WARNING:
		printf(TERM_COLOR_YELLOW "[WARNING] " TERM_COLOR_DEFAULT);
		break;
	case MESSAGE_DEBUG:
		printf(TERM_COLOR_MAGENTA "[DEBUG] " TERM_COLOR_DEFAULT);
		break;
	case MESSAGE_SUCCESS:
		printf(TERM_COLOR_GREEN "[SUCCESS] " TERM_COLOR_DEFAULT);
		break;
	default:
		break;
	}
}

// Print help for -h command line option
void print_help(void)
{
	print_messages(MESSAGE_INFO);
	printf("Help for the Battleships Controller program\n");
	printf("    Command line parameters:\n");
	printf("    -h                           : Print this help\n");
	printf("    -s d=port_file,s=baud_rate   : Set serial port device file (/dev/tty*) and baud rate\n");
	printf("    -o file                      : File to store high scores\n");
	printf("    When connected, use the WASD keys to move the cursor, press E to shoot, R to reset the game, and Q to quit.\n");
}

int terminal_setup(bool reset)
{
	static struct termios oldt, newt;
	static bool firstrun = true;

	// tcgetattr gets the parameters of the current terminal STDIN_FILENO will tell tcgetattr that it should write the settings of stdin to oldt
	if (firstrun)
	{
		if (tcgetattr(STDIN_FILENO, &oldt) == -1)
		{
			print_messages(MESSAGE_ERROR);
			perror("Error while getting terminal attributes.");
			exit(EXIT_FAILURE);
		}

		newt = oldt;

		if (atexit(exit_function) != 0)
		{
			print_messages(MESSAGE_ERROR);
			perror("Error while setting exit function.");
		}

		// ICANON normally takes care that one line at a time will be processed that means it will return if it sees a "\n" or an EOF or an EOL
		newt.c_lflag &= ~(ICANON | ECHO);
		firstrun = false;
	}

	// Those new settings will be set to STDIN TCSANOW tells tcsetattr to change attributes immediately.
	if (reset)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	}
	else
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	}
	return 0;
}

void plot_results(void)
{
	if (CMDLINE_DBG)
	{
		print_messages(MESSAGE_DEBUG);
		printf("Plotting results...\n");
	}
	if (g_outfile_fp == NULL)
	{
		print_messages(MESSAGE_ERROR);
		perror("Error while opening output file.");
		exit(EXIT_FAILURE);
	}
	FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
	if (gnuplotPipe == NULL)
	{
		print_messages(MESSAGE_ERROR);
		perror("Error while opening gnuplot pipe.");
		exit(EXIT_FAILURE);
	}
	fprintf(gnuplotPipe, "set title \"Game results\"\n");
	fprintf(gnuplotPipe, "set xlabel \"Step nr.\"\n");
	fprintf(gnuplotPipe, "set ylabel \"Points\"\n");
	fprintf(gnuplotPipe, "set terminal dumb\n");
	fprintf(gnuplotPipe, "set datafile separator \",\"\n");
	fprintf(gnuplotPipe, "plot \"%s\" using 2:3 with lines\n", g_outfile);
	fprintf(gnuplotPipe, "exit\n");
}

int main(int argc, char *argv[])
{
	int opt;
	int i;

	// Stuff required by getopt-subopt handling for the serial port
	enum
	{
		DEVICE_OPT = 0,
		SPEED_OPT
	};

	char *const token[] = {
		[DEVICE_OPT] = "d",
		[SPEED_OPT] = "s",
		NULL};

	char *subopts;
	char *value;
	int errfnd = 0;

	// No arguments provided in command line
	if (argc <= 1)
	{
		print_messages(MESSAGE_WARNING);
		printf("No command line parameters, using default options.\n");
	}

	// Printing command line arguments if CMDLINE_DBG is set
	if (CMDLINE_DBG)
	{
		print_messages(MESSAGE_DEBUG);
		printf("The arguments supplied are (ARG_NUM: ARG_VALUE):\n");
		for (i = 0; i < argc; i++)
		{
			printf("    %d: %s\n", i, argv[i]);
		}
	}

	// Handling commmad line arguments, and storing them in globals
	while ((opt = getopt(argc, argv, "hs:o:i:")) != -1)
	{
		switch (opt)
		{
		case 'h':
			if (CMDLINE_DBG)
			{
				print_messages(MESSAGE_DEBUG);
				printf("-h cmd line par received, printing help\n");
			}
			print_help();
			exit(EXIT_SUCCESS);
			break;

		case 's':
			if (CMDLINE_DBG)
			{
				print_messages(MESSAGE_DEBUG);
				printf("-s cmd line par received, setting serial port\n");
			}
			subopts = optarg;
			while ((*subopts != '\0') && !errfnd)
			{
				switch (getsubopt(&subopts, token, &value))
				{
				case DEVICE_OPT:
					if (strlen(value) < CFGSTR_SIZE)
					{
						strcpy(g_serial_device, value);
						if (CMDLINE_DBG)
						{
							print_messages(MESSAGE_DEBUG);
							printf("Serial port: %s\n", g_serial_device);
						}
					}
					else
					{
						print_messages(MESSAGE_ERROR);
						perror("Serial device file name is too long!");
						printf(" (max size is %d), exiting...\n", CFGSTR_SIZE);
						exit(EXIT_FAILURE);
					}
					break;
				case SPEED_OPT:
					g_serial_speed = atoi(value);
					if (g_serial_speed == 0)
					{
						print_messages(MESSAGE_ERROR);
						perror("Serial device speed is invalid, exiting...\n");
						exit(EXIT_FAILURE);
					}
					break;
				}
			}
			break;
		case 'o':
			if (CMDLINE_DBG)
			{
				print_messages(MESSAGE_DEBUG);
				printf("-o cmd line par received, setting output file\n");
			}
			if (strlen(optarg) < FILENAME_SIZE)
			{
				strcpy(g_outfile, optarg);
				if (CMDLINE_DBG)
				{
					print_messages(MESSAGE_DEBUG);
					printf("Output file: %s\n", g_outfile);
				}
			}
			else
			{
				print_messages(MESSAGE_ERROR);
				perror("Output file name is too long!");
				printf("(max size is %d), exiting...\n", FILENAME_SIZE);
				exit(EXIT_FAILURE);
			}
			break;
		default:
			if (CMDLINE_DBG)
			{
				print_messages(MESSAGE_DEBUG);
				printf("Unknown command line parameter is received\n");
			}
			break;
		}
	}

	terminal_setup(false);

	struct termios gecko_ser;
	int ser_fd; // file descriptors
	int out_fd;
	int step = 0;
	int score = 0;

	// clearing struct (fill w/ 0s)
	memset(&gecko_ser, 0, sizeof(gecko_ser));
	// serial communication settings
	gecko_ser.c_iflag = 0;
	gecko_ser.c_oflag = 0;
	gecko_ser.c_cflag = CS8 | CREAD | CLOCAL; // character size mask ==> 8-bit communication | enable receiver | modem control lines
	gecko_ser.c_lflag = 0;
	gecko_ser.c_cc[VMIN] = 1;  // minimum number of characters for nonchanonical read
	gecko_ser.c_cc[VTIME] = 5; // timeout in deciseconds (1/10s) for noncanonical read

	// speed setting
	if (set_g_speed(g_serial_speed))
	{
		print_messages(MESSAGE_INFO);
		printf("Serial port speed: %d (%#x)\n", g_serial_speed, g_termio_speed);
	}
	else
	{
		print_messages(MESSAGE_ERROR);
		perror("Specified serial speed is not supported by termios.h\n");
		exit(EXIT_FAILURE);
	}
	ser_fd = open(g_serial_device, O_RDWR);
	if (ser_fd < 0) // check for errors
	{
		print_messages(MESSAGE_ERROR);
		sleep(1);
		perror("Failed to open serial device!");
		exit(EXIT_FAILURE);
	}
	else
	{
		print_messages(MESSAGE_INFO);
		printf("Serial device %s opened successfully!\n", g_serial_device);
	}

	cfsetospeed(&gecko_ser, g_termio_speed); // output speed
	cfsetispeed(&gecko_ser, g_termio_speed); // input speed

	tcsetattr(ser_fd, TCSANOW, &gecko_ser);
	write(ser_fd, "r", 1);

	g_outfile_fp = fopen(g_outfile, "w+");

	if (g_outfile_fp == NULL)
	{
		print_messages(MESSAGE_ERROR);
		perror("Error while opening output file");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (CMDLINE_DBG)
		{
			print_messages(MESSAGE_DEBUG);
			printf("Output file opened successfully\n");
		}
	}

	char linebuf_in[BUFLEN];	 // buffer for reading from terminal
	char linebuf_out[BUFLEN];	 // buffer for reading from serial port
	struct pollfd pfds[PFDSLEN]; // poll file descriptors

	pfds[0].fd = STDIN_FILENO;
	pfds[0].events = POLLIN;
	pfds[1].fd = ser_fd;
	pfds[1].events = POLLIN;

	int timeout = 1000; // timeout in ms
	time_t start_time;
	time(&start_time);

	bool looping = true;
	// main loop
	while (looping)
	{
		int ret = poll(pfds, PFDSLEN, timeout);

		if (ret == -1)
		{
			print_messages(MESSAGE_ERROR);
			perror("Poll error\n");
			exit(EXIT_FAILURE);
		}
		else if (ret > 0)
		{
			if (pfds[0].revents & POLLIN)
			{
				ssize_t n = read(STDIN_FILENO, linebuf_in, BUFLEN);

				if ((n == 1) && (linebuf_in[0] == 'q'))
				{
					// exit when q is pressed
					looping = false;
				}
				else if ((n == 1) && (linebuf_in[0] == 'r'))
				{
					write(ser_fd, "r", 1);
					step = 0;
					score = 0;
					time(&start_time);
					freopen(g_outfile, "w+", g_outfile_fp);
					if (g_outfile_fp == NULL)
					{
						print_messages(MESSAGE_ERROR);
						perror("Error while reopening output file");
						exit(EXIT_FAILURE);
					}
					else
					{
						if (CMDLINE_DBG)
						{
							print_messages(MESSAGE_DEBUG);
							printf("Output file reopened successfully\n");
						}
					}
				}
				else
				{
					write(ser_fd, linebuf_in, n);
				}
			}
			if (pfds[1].revents & POLLIN)
			{
				ssize_t n = read(ser_fd, linebuf_out, BUFLEN);
				if (CMDLINE_DBG)
				{
					print_messages(MESSAGE_DEBUG);
					printf("Serial output line buffer: %s\n", linebuf_out);
				}

				for (int i = 0; i < n; i++)
				{
					time_t current_time;
					time(&current_time);
					struct tm *current_time_local = localtime(&current_time);
					if (linebuf_out[i] == '0')
					{
						step++;
						fprintf(g_outfile_fp, "%s, %d, %d\n", strtok(asctime(current_time_local), "\n"), step, score);
					}
					else if (linebuf_out[i] == '1')
					{
						step++;
						fprintf(g_outfile_fp, "%s, %d, %d\n", strtok(asctime(current_time_local), "\n"), step, ++score);
						fflush(g_outfile_fp);
					}
					else if (linebuf_out[i] == 'x')
					{

						// end of game, display results
						print_messages(MESSAGE_SUCCESS);
						printf("Congratulations! You have completed the game! It took you %d steps and %.1f seconds.\n", step, difftime(current_time, start_time));

						looping = false;
						plot_results();
					}
				}
			}
		}
		else
		{
			if (CMDLINE_DBG)
			{
				print_messages(MESSAGE_DEBUG);
				printf("Timeout\n");
			}
		}
	}
	// Exiting
	exit(EXIT_SUCCESS);
}
