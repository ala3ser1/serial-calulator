#define ADC0808 1
#define TYPE ADC0808
#if(TYPE==1)
#ifndef __adc_h__
#define __adc_h__
#define A P3^3
#define B P3^4
#define C P3^5
#define ALE P3^6
#define OE P3^7
#define ADC_DATA P1
#define EOC P2^1
#define START P2^0
sbit start =START;
sbit eoc=EOC;
sbit a=A;
sbit b=B;
sbit c=C;
sbit ale=ALE;
sbit oe=OE;
void adcIntialize(void);
void adcstart(void);
#endif
#endif