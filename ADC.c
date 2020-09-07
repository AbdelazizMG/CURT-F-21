/*
 * ADC.c
 *
 * Created: 9/7/2020 3:29:29 PM
 *  Author: Abdulazez
 */ 
#include "ADC.h"


void ADC_Enable(void)
{
	SetBit(ADCSRA->allregister,ADEN);  // Enable 
	ADMUX->allregister=0;
	SetBit(ADMUX->allregister,PIN6); // Voltage Reference
	ClearBit(ADMUX->allregister,PIN7);
}
void ADC_Start_conv(void)
{
	SetBit(ADCSRA->allregister,ADSC);
}
void Select_Channel(Channel channel)
{
	SetFloatInput(GPIOA,channel);
	ADMUX->allregister &= 0xE0 ; //Setting it to 0
	ADMUX->allregister |= channel;
}
u16 ADC_GetRead_Polling(void)
{
	u16 read=0;    // ADC -> 10 Bit  ... Register 8 Bit  .. Two Registers with filled 10 bits and 6 of zero
	while (CheckBit(ADCSRA->allregister,ADSC));      
	read = ADCL->allregister | (ADCH->allregister<<8) ;
	return read;
}