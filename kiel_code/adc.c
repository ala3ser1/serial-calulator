#include "reg51.h"
#include"adc.h"

void adcIntialize(void)
{
	start=0;
	ale=0;
	oe=0;
	eoc=1;
}

void adcstart(void)
{
	ale=1;
	start=1;
	ale=0;
	start=0;
}
