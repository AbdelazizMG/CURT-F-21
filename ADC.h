/*
 * ADC.h
 *
 * Created: 9/7/2020 3:29:17 PM
 *  Author: Abdulazez
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "GPIO.h"

#define ADMUX  ((Register*)0x27)
#define ADCSRA ((Register*)0x26)
#define ADCL   ((Register*)0x24)
#define ADCH   ((Register*)0x25)

#define ADEN 7
#define ADSC 6



typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
}Channel;

void ADC_Enable(void);
void ADC_Start_conv(void);
void Select_Channel(Channel channel);
u16 ADC_GetRead_Polling(void);

#endif /* ADC_H_ */