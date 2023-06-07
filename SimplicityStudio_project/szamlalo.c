#include "segmentlcd_individual.h"
#include <stdbool.h>
#include <em_lcd.h>
#include "segmentlcd.h"
#include "fuggvenyek.h"
#include "szamlalo.h"

SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];
SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

//Ez a f�ggv�ny 0-t�l 9-ig k�pes az adott fels� szegmensen egy sz�mot kijelezni
int felso_segment(int szam, int segment){
	int i=szam;
	if (szam==0){
		i=10;
	}
	switch (i){
		case 1:
			upperCharSegments[segment].a = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 2:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 3:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 4:
			upperCharSegments[segment].a = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 5:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 6:
			upperCharSegments[segment].a = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 7:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 8:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 9:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
		case 10:
			upperCharSegments[segment].a = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].b = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].c = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].d = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].e = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].f = 1;
			SegmentLCD_UpperSegments(upperCharSegments);
			upperCharSegments[segment].g = 0;
			SegmentLCD_UpperSegments(upperCharSegments);
			break;
	}
	return 1;
}
//A sz�ml�l� amely seg�ts�g�vel ki lehet jelezni az adott sz�mot.
//El�sz�r helyi�rt�kekre bontja, majd kijelzi azokat a megfelel� szegmensen
int szamlalo(int szam){
	int E = (szam/1000); // Ezres helyi�rt�k
	int sz = (szam%1000)/100; // Sz�zas helyi�rt�k
	int t = (szam%100)/10; // Tizes helyi�rt�k
	int e = (szam%10); //Egyes helyi�rt�k
	felso_segment (E, 3);
	felso_segment (sz, 2);
	felso_segment (t, 1);
	felso_segment (e, 0);
	return 1;
}


