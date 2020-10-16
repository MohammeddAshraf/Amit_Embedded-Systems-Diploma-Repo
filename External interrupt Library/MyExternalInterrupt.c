/*
 * MyExternalInterrupt.c
 *
 * Created: 16-Oct-20 2:40:39 AM
 *  Author: Mohammed Ashraf
 */
#include <avr/io.h>        //Atmega32a library.
#include <avr/interrupt.h> //Interrupt library.

#define FallingMode			0
#define RisingMode			1
#define AnyLogiclChangeMode 2
#define LowLevelMode		3

void INT0_init(int mode)
{
	switch (mode)
	{
		case FallingMode:           //Falling Sense Control.
		MCUCR |=  (1<<ISC01);
		MCUCR &= ~(1<<ISC00);
		break;
		
		case RisingMode:           //Rising Sense Control.
		MCUCR |= (1<<ISC01);
		MCUCR |= (1<<ISC00);
		break;
		
		case AnyLogiclChangeMode: //Any Logical Change Sense Control.
		MCUCR &= ~(1<<ISC01);
		MCUCR |=  (1<<ISC00);
		break;
		
		case LowLevelMode:        //Low Level Sense Control.
		MCUCR &= ~(1<<ISC01);
		MCUCR &= ~(1<<ISC00);
		break;
	}
	
	GICR |= (1<<INT0);            //Enable INT0.
}
void INT1_init(int mode)
{
	switch (mode)
	{
		case FallingMode:         //Falling Sense Control.
		MCUCR |=  (1<<ISC11);
		MCUCR &= ~(1<<ISC10);
		break;
		
		case RisingMode:	      //Rising Sense Control.
		MCUCR |= (1<<ISC11);
		MCUCR |= (1<<ISC10);
		break;
		
		case AnyLogiclChangeMode: //Any Logical Change Sense Control.
		MCUCR &= ~(1<<ISC11);
		MCUCR |=  (1<<ISC10);
		break;
		
		case LowLevelMode:		  //Low Level Sense Control.
		MCUCR &= ~(1<<ISC11);
		MCUCR &= ~(1<<ISC10);
		break;
	}
	
	GICR |= (1<<INT1);            //Enable INT1.
}
void INT2_init(int mode)
{
	switch (mode)
	{
		case FallingMode:         //Falling Sense Control.
		MCUCSR &= ~(1<<ISC2);
		break;
		
		case RisingMode:	      //Rising Sense Control.
		MCUCSR |= (1<<ISC2);
		break;
	}
	
	GICR |= (1<<INT2);            //Enable INT2.
}