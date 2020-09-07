/*
 * Macros.h
 *
 * Created: 9/7/2020 12:59:14 PM
 *  Author: Abdulazez
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SetBit(Reg,Bit) Reg|= 1<<Bit 
#define ClearBit(Reg,Bit) Reg &= ~(1 << Bit)
#define CheckBit(Reg,Bit) ( Reg >> Bit & 1 )



#endif /* MACROS_H_ */