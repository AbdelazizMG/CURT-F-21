/*
 * LM35.c
 *
 * Created: 9/7/2020 3:30:03 PM
 *  Author: Abdulazez
 */ 

#include "LM35.h"

u16 GetTemperature(Channel channel)
{
	u16 temp =0;
	u16 ADC_Read=0;
	Select_Channel(channel);
	ADC_Start_conv();
	ADC_Read= ADC_GetRead_Polling();
	temp = ((u64) ADC_Read * 150) / 307 ;
	return temp;
}