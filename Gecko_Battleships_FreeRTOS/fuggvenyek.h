

#ifndef SRC_FUGGVENYEK_H_
#define SRC_FUGGVENYEK_H_

void SysTick_Handler(void);

int elrendezes(int* alapallas);

void kurzor(int segmentnum, int segmentchar);

bool loves(int* alapallas, int x, int y, int* sullyedt, int a);

void kijelez(int* sullyedt, int k);

void vege();

#endif /* SRC_FUGGVENYEK_H_ */
