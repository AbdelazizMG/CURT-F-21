/*
 * CURTF'21.c
 *
 * Created: 9/7/2020 12:50:27 PM
 * Author : Abdelazez
 */ 


#include "LM35.h"



int main(void)
{
	SetOutput(GPIOA,PIN0); // GREEN
	SetOutput(GPIOA,PIN1); // RED
	SetOutput(GPIOA,PIN2); // Yellow
	SetOutput(GPIOB,PIN0); //Buzzer
	SetFloatInput(GPIOA,PIN7); //LM35
	ADC_Enable();
	long temperature=0;
    
    while (1) 
    {
		temperature=GetTemperature(ADC7);
		if(temperature<20)
		{ WriteOutput(GPIOA,PIN0,HIGH); //GREEN ON
		  WriteOutput(GPIOA,PIN2,LOW);
		  WriteOutput(GPIOA,PIN1,LOW);
		  WriteOutput(GPIOB,PIN0,LOW);
		}
		else if (temperature >20 && temperature<40) 
		{ WriteOutput(GPIOA,PIN2,HIGH); // Yellow ON
		  WriteOutput(GPIOA,PIN0,LOW);
		  WriteOutput(GPIOA,PIN1,LOW);
		  WriteOutput(GPIOB,PIN0,LOW);
		}
		else if (temperature > 40)
		{ WriteOutput(GPIOA,PIN1,HIGH); //RED ON
		  WriteOutput(GPIOB,PIN0,HIGH); //Buzzer ON
		  WriteOutput(GPIOA,PIN0,LOW);
		  WriteOutput(GPIOA,PIN2,LOW);
		} 
		
    }
}

