// header guard
#ifndef SERIAL_H
#define SERIAL_H

// Standard C libraries
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

// Global variables to store configuration parameters
#define CFGSTR_SIZE 64
#define FILENAME_SIZE 1024
#define TTYLINE_SIZE 256

// ANSI escape codes for terminal colors
#define TERM_COLOR_RED "\033[0;31m"
#define TERM_COLOR_GREEN "\033[0;32m"
#define TERM_COLOR_YELLOW "\033[0;33m"
#define TERM_COLOR_BLUE "\033[0;34m"
#define TERM_COLOR_MAGENTA "\033[0;35m"
#define TERM_COLOR_DEFAULT "\033[0m"

// Message types for print_message()
#define MESSAGE_INFO 0
#define MESSAGE_WARNING 1
#define MESSAGE_ERROR 2
#define MESSAGE_DEBUG 3
#define MESSAGE_SUCCESS 4

#define BUFLEN (32) // Length of line buffer
#define PFDSLEN (2) // Number of file descriptors to monitor

// Accessing termios.h Bnum type speed definition from the command line
struct BNUM_speed
{
	uint32_t speed;
	uint32_t bnum;
};

char *optarg; // To avoid VSCODE nagging about optarg not being declared

bool set_g_speed(int speed);

void print_messages(int message_type);

void print_help(void);

int terminal_setup(bool reset);

void exit_function(void);

void plot_results(void);

int main(int argc, char *argv[]);

#endif // SERIAL_H