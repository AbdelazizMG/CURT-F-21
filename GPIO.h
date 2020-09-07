/*
 * GPIO.h
 *
 * Created: 9/7/2020 12:51:42 PM
 *  Author: Abdulazez
 */ 



#ifndef GPIO_H_
#define GPIO_H_

#include "StdTypes.h"
#include "Macros.h"

#define GPIOA ((GPIO*)0x39) // Casting using pointers to make it have the same address
#define GPIOB ((GPIO*)0x36) 
#define GPIOC ((GPIO*)0x33)
#define GPIOD ((GPIO*)0x30)


typedef union
{
	vu8 allregister;
	struct  
	{
		vu8 Bit0:1;
		vu8 Bit1:1;
		vu8 Bit2:1;
		vu8 Bit3:1;
		vu8 Bit4:1;
		vu8 Bit5:1;
		vu8 Bit6:1;
		vu8 Bit7:1;
	}Bits;
	
}Register;

typedef struct
{
	Register PIN;
	Register PORT;
	Register DDR;
}GPIO;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}PIN_number;

typedef enum
{
	LOW,
	HIGH,
}Value;


void SetOutput(GPIO *gpio,PIN_number pin);
void SetFloatInput (GPIO *gpio,PIN_number pin );
void WriteOutput(GPIO *gpio ,PIN_number pin, Value value1);

#endif /* GPIO_H_ */