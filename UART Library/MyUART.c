/*
 * MyUART.c
 *
 * Created: 06-Nov-20 4:15:40 PM
 *  Author: Mohammed Ashraf
 */ 
#include <avr/io.h>
#include "MyUART.h"
#include <stdlib.h>

void UART_init()
{
	//UCSRA
	UCSRB |= (1<<TXEN)|(1<<RXEN); //Enable UART Tx and Rx.
	UBRRL = 103; //where UBBR = ((F_CPU)/(16*BAUD))-1 ,,, if UBBR <255 -> UBBRL = UBBR ,,, Else -> UBBRH = UBBR.
}
void UART_Send_Char(char data)
{
	while(!(UCSRA & (1<<UDRE))); //Pooling
	UDR = data;
}
void UART_Send_Str(char* str)
{
	for(int i = 0;str[i]!= '\0';i++)
	{
		UART_Send_Char(str[i]);
	}
}
void UART_Send_Num(int num)
{
	char str[10];
	itoa(num, str,10);
	UART_Send_Str(str);
}
char UART_Receive()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}