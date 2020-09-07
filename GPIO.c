/*
 * GPIO.c
 *
 * Created: 9/7/2020 12:51:57 PM
 *  Author: Abdulazez
 */ 

#include "GPIO.h"


void SetOutput(GPIO *gpio,PIN_number pin)
{
	SetBit(gpio->DDR.allregister, pin);
}
void SetFloatInput (GPIO *gpio,PIN_number pin )
{
	ClearBit(gpio->DDR.allregister,pin);
	ClearBit(gpio->PORT.allregister,pin);
}
void WriteOutput(GPIO *gpio ,PIN_number pin, Value value1)
{
	if(value1)
	{
		SetBit(gpio->PORT.allregister,pin);
	}
	else
	{
		ClearBit(gpio->PORT.allregister,pin);
	}
}