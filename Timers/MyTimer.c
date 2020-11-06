/*
 * MyTimer.c
 *
 * Created: 29-Oct-20 12:06:35 PM
 *  Author: Mohammed Ashraf
 */ 
#include "MyTimer.h"
/*

//Interrupt Service Routine

ISR(TIMER0_OVF_vect)
{
	
	//clk = 16000000/1024 = 15625 cycles.
	//15625/255 = 61 over flow per second.
	
	static int count =0 ;
	count++;
	
	if(count==61) //Once every second.
	{
		PORTC ^= (1<<0);
		count = 0;
	}
}
*/

#include <avr/io.h>

void Timer0_clkSource(int clk)
{
	TCCR0 |= clk;
}
void Timer0_Mode(int mode)
{
	TCCR0 |= mode;
}
void Timer0_OC0_Mode(int mode)
{
	DDRB |= (1<<3);
	TCCR0 |= (mode<<4);
}
void Timer0_Interrupt(int Timer_Interrupt)
{
	if(Timer_Interrupt == 3)
	{
		TIMSK &= ~((1<<0)|(1<<1));
	}
	else
	{
		TIMSK |= (1<<Timer_Interrupt);
	}
}
void Timer_OC0_DutyCycle(int DutyCycle)
{
	OCR0 = 2.55*(float)DutyCycle;
}
void Timer0_init(int Time_Mode,int OC0_Mode,int DutyCycle,int clk)
{
	Timer0_Mode(Time_Mode);					//Timer0 Mode
	Timer0_OC0_Mode(OC0_Mode);				//OC0 Mode
	//Timer0_Interrupt(TOV_INT);			//OverFlow Mode
	Timer_OC0_DutyCycle(DutyCycle);		//CompareMatch Value
	Timer0_Interrupt(TOC_INT);				//CompareMatch Mode
	Timer0_clkSource(clk);					//Timer0 State
}
