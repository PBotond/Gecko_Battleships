#include <stdlib.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"

//USART_InitAsync_TypeDef UART0_init;
SegmentLCD_UpperCharSegments_TypeDef UpperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];
SegmentLCD_LowerCharSegments_TypeDef LowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

//A haly�k elrendez�s�t meghat�roz� f�ggv�ny
//A 16 esetb�l random v�laszt ki egyet
int elrendezes(int* alapallas){
	int rand_num;
	rand_num = (rand() % (16));
	switch (rand_num){
		case 0:{;
			int allas[16]={0, 13, 1, 13, 2, 9, 2, 12, 3, 2, 3, 3, 5, 1, 6, 1};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 1:{;
			int allas[16]={0, 6, 0, 5, 0, 2, 0, 3, 3, 7, 3, 10, 5, 1, 6, 1};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 2:{;
			int allas[16]={1, 13, 2, 13, 3, 2, 3, 3, 4, 2, 4, 3, 6, 7, 6, 10};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 3:{;
			int allas[16]={0, 1, 1, 1, 2, 9, 2, 12, 4, 4, 5, 4, 6, 7, 6, 10};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 4:{;
			int allas[16]={2, 6, 2, 5, 2, 2, 2, 3, 4, 8, 4, 11, 5, 4, 6, 4};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 5:{;
			int allas[16]={0, 13, 1, 13, 2, 2, 2, 3, 4, 7, 4, 10, 6, 12, 6, 9};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 6:{;
			int allas[16]={0, 7, 0, 10, 1, 7, 1, 10, 5, 12, 5, 9, 6, 12, 6, 9};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 7:{;
			int allas[16]={0, 1, 1, 1, 2, 4, 3, 4, 4, 13, 5, 13, 6, 2, 6, 3};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 8:{;
			int allas[16]={1, 6, 1, 5, 2, 7, 2, 10, 4, 13, 5, 13, 6, 7, 6, 10};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 9:{;
			int allas[16]={0, 4, 1, 4, 2, 7, 2, 10, 3, 2, 3, 3, 5, 2, 5, 3};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 10:{;
			int allas[16]={0, 1, 1, 1, 2, 8, 2, 11, 3, 9, 3, 12, 5, 13, 6, 13};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 11:{;
			int allas[16]={0, 7, 0, 10, 2, 7, 2, 10, 3, 2, 3, 3, 5, 13, 6, 13};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 12:{;
			int allas[16]={2, 13, 3, 13, 4, 7, 4, 10, 5, 7, 5, 10, 6, 2, 6, 3};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 13:{;
			int allas[16]={0, 1, 1, 1, 2, 13, 3, 13, 4, 8, 4, 11, 5, 5, 5, 6};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 14:{;
			int allas[16]={1, 2, 1, 3, 2, 2, 2, 3, 4, 1, 5, 1, 6, 8, 6, 11};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
		case 15:{;
			int allas[16]={1, 12, 1, 9, 2, 9, 2, 12, 3, 4, 4, 4, 5, 13, 6, 13};
			for(int i=0; i<16; i++){
				alapallas[i]=allas[i];
			}
			break;}
	}
	return 1;
}

// A kurzor villogtat�s��rt felel�s f�ggv�ny.
// Az X szegmensen bel�l a 13 elhelyezked�s valamelyik�t villogtatja.
void kurzor(int segmentnum, int segmentchar){
	switch(segmentchar){
		case 1:
			//Az 'a' szegmens
			LowerCharSegments[segmentnum].a = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].a = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 2:
			//Az 'b' szegmens
			LowerCharSegments[segmentnum].b = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].b = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 3:
			//Az 'c' szegmens
			LowerCharSegments[segmentnum].c = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].c = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 4:
			//Az 'd' szegmens
			LowerCharSegments[segmentnum].d = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].d = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 5:
			//Az 'e' szegmens
			LowerCharSegments[segmentnum].e = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].e = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 6:
			//Az 'f' szegmens
			LowerCharSegments[segmentnum].f = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].f = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 7:
			//Az 'h' szegmens
			LowerCharSegments[segmentnum].h = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].h = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 8:
			//Az 'j' szegmens
			LowerCharSegments[segmentnum].j = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].j = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 9:
			//Az 'k' szegmens
			LowerCharSegments[segmentnum].k = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].k = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 10:
			//Az 'n' szegmens
			LowerCharSegments[segmentnum].n = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].n = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 11:
			//Az 'p' szegmens
			LowerCharSegments[segmentnum].p = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].p = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 12:
			//Az 'q' szegmens
			LowerCharSegments[segmentnum].q = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			LowerCharSegments[segmentnum].q = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);

			break;
		case 13:
			//Az 'g-m' szegmens
			LowerCharSegments[segmentnum].g = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
			LowerCharSegments[segmentnum].m = 1;
			SegmentLCD_LowerSegments(LowerCharSegments);
      vTaskDelay(200);
			LowerCharSegments[segmentnum].g = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
			LowerCharSegments[segmentnum].m = 0;
			SegmentLCD_LowerSegments(LowerCharSegments);
			vTaskDelay(200);
			break;
	}
}

//A l�v�s�rt felel�s f�ggv�ny
bool loves(int* alapallas, int x, int y, int* sullyedt, int a){
	//El�sz�r sorba felvillantjuk a ring szegmenseit
	for (int i=0; i<8; i++){
		SegmentLCD_ARing(i,1);
		vTaskDelay(100);
	}
	//Megvizsg�lju, hogy ez a kordin�ta el lett-e m�r s�llyesztve.
	//Ha m�r els�llyedt akkor nem vessz�k tal�latnak, kikapcsoljuk a ringet.
	for(int j=0; j<a+1; j+=2){
		if(sullyedt[j]==x && sullyedt[j+1]==y){
			for (int i=0; i<8; i++){
				SegmentLCD_ARing(i,0);
				vTaskDelay(100);
			}
			return false;
		}
	}
	//Megvizsg�ljuk, hogy szerepel-e ezen a koordin�t�n haj�, amit m�g nem l�tt�nk ki
	//Ha igen akkor 5-sz�r villogtatjuk a ringet �s tal�latnak vessz�k
	for (int i=0; i<15; i+=2){
		if(alapallas[i]==x && alapallas[i+1]==y){
			for (int k=0; k<5; k++){
				for (int j=0; j<8; j++){
					SegmentLCD_ARing(j,1);
				}
				vTaskDelay(100);
				for (int j=0; j<8; j++){
					SegmentLCD_ARing(j,0);
				}
				vTaskDelay(100);
			}
			return true;
		}
	}
	//Ha nem tal�lt akkor kikapcsoljuk a ringet.
	for (int i=0; i<8; i++){
		SegmentLCD_ARing(i,0);
	}
	return false;
}

//Kijelezz�k, az eddig els�llyesztett koordin�t�kon l�v� haj�kat.
void kijelez(int* sullyedt, int k){
	for(int i=0; i<k-1; i+=2){
		switch(sullyedt[i+1]){
			case 1:
				LowerCharSegments[sullyedt[i]].a = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 2:
				LowerCharSegments[sullyedt[i]].b = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 3:
				LowerCharSegments[sullyedt[i]].c = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 4:
				LowerCharSegments[sullyedt[i]].d = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 5:
				LowerCharSegments[sullyedt[i]].e = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 6:
				LowerCharSegments[sullyedt[i]].f = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 7:
				LowerCharSegments[sullyedt[i]].h = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 8:
				LowerCharSegments[sullyedt[i]].j = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 9:
				LowerCharSegments[sullyedt[i]].k = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 10:
				LowerCharSegments[sullyedt[i]].n = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 11:
				LowerCharSegments[sullyedt[i]].p = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 12:
				LowerCharSegments[sullyedt[i]].q = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
			case 13:
				LowerCharSegments[sullyedt[i]].g = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				LowerCharSegments[sullyedt[i]].m = 1;
				SegmentLCD_LowerSegments(LowerCharSegments);
				break;
		}
	}
}
void vege_clear(){
  for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_LOWER_CHARS; p++) {
     LowerCharSegments[p].raw = 0;
     SegmentLCD_LowerSegments(LowerCharSegments);
  }
}

//Ha a jt�knak v�ge, akkor t�r�lj�k az als� szegmenseket �s ki�rjuk, hogy "WIN"
void vege(){
	//W
	LowerCharSegments[1].f = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[1].e = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[1].q = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[1].n = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[1].b = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[1].c = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);

	//I
	LowerCharSegments[2].b = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[2].c = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);

	//N
	LowerCharSegments[3].f = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[3].e = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[3].h = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[3].n = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[3].b = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
	LowerCharSegments[3].c = 1;
	SegmentLCD_LowerSegments(LowerCharSegments);
}
