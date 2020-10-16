/*
 * LCD_16x2_Testing.c
 *
 * Created: 09-Oct-20 11:29:43 PM
 * Author : Mohammed Ashraf
 */ 
#define F_CPU 16000000UL //Bafahem el delay el freq beta3ty kam.
#include <util/delay.h> //Delay library
#include <avr/io.h> //Atmega32a library.
#include "MyLCD.h"

int main(void)
{
    LCD_init();
	
    while (1) 
    {
		LCD_write_str("I LOVE YOU FOFA");
		_delay_ms(1000);
		LCD_clear();
		LCD_write_str("YOU LOVE ME? :(");
		_delay_ms(1000);
		LCD_clear();
    }
}
