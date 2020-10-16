/*
 * MyLCD.c
 *
 * Created: 11-Oct-20 8:45:36 PM
 *  Author: Mohammed Ashraf
 */ 

#include <stdlib.h>
#define F_CPU 16000000UL	   //My Microprocessor frequency.
#include <util/delay.h>		   //Delay library
#include <avr/io.h>			   //Atmega32a library.

#define RS				 1     //Pin connected to RS.
#define RW				 2     //Pin connected to RW.
#define E				 3     //Pin connected to E.
#define LCD_Command_Port PORTB //RS,RW,E are on which PORTx.
#define LCD_Command_Dir  DDRB  //RS,RW,E are on which DDRx.
#define LCD_Data_Port    PORTA //D0->D7 on which PORTx.
#define LCD_Data_Dir     DDRA  //D0->D7 on which DDRx.

//Choose the mode by changing which section is commented.

									//8-bit Mode
/*
void LCD_cmd(char cmd)
{
	LCD_Command_Port &= ~(1<<RS); //RS to LOW to receive command.
	LCD_Data_Port = cmd;
	LCD_Command_Port |=  (1<<E);  //
	_delay_ms(1);				  //Giving the pulse to receive command.
	LCD_Command_Port &= ~(1<<E);  //
}
void LCD_init()
{
	LCD_Data_Dir = 0xFF;						   //DDRx for D0->D7
	LCD_Command_Dir |= ((1<<RS)|(1<<E)|(1<<RW));   //DDRx for RS,E,RW
	LCD_Command_Port &= ~(1<<RW);				   //RW to LOW to write on LCD.
	LCD_cmd(0x38);						           //8-bits mode
	_delay_ms(1);
	LCD_cmd(0x01);						           //Clears LCD Screen.
	_delay_ms(1);
	LCD_cmd(0x02);						           //Return home.
	_delay_ms(1);
	LCD_cmd(0x06);
	_delay_ms(1);
	LCD_cmd(0x80);						           //Put the cursor in the first line.
	_delay_ms(1);
	LCD_cmd(0x0C);						           //Display ON, cursor OFF.
	//LCD_cmd(0x0E);					           //Display ON, cursor ON.
	_delay_ms(1);
}
void LCD_clear()
{
	_delay_ms(1);
	LCD_cmd(0x01);
	_delay_ms(1);
}
void LCD_write_char(char data)
{
	LCD_Command_Port |= (1<<RS); //RS to HIGH to receive data.
	LCD_Data_Port = data;
	LCD_Command_Port |=  (1<<E); //
	_delay_ms(1);				 //Giving the pulse to receive data.
	LCD_Command_Port &= ~(1<<E); //
}
void LCD_write_str(char* str)
{
	for(int i=0;str[i] !='\0';i++)
	{
		LCD_write_char(str[i]);
	}
}
void LCD_goto_xy(int x,int y)
{
	if(x==1 && y<16)
	{
		LCD_cmd(0x80|y);
	}
	else if(x==2 && y<16)
	{
		LCD_cmd(0xC0|y);
	}
	else LCD_write_str("Out of dimension");
}
void LCD_write_int(int num)
{
	char str[10];
	itoa(num,str,10);
	LCD_write_str(str);
}
*/

									//4-bit Mode

void LCD_cmd(char cmd)
{
	LCD_Command_Port &= ~(1<<RS); //RS to LOW to receive command.
	//First half of the command.
	LCD_Data_Port &=0x0F;
	LCD_Data_Port |= (0xF0&cmd);
	LCD_Command_Port |=  (1<<E);  //
	_delay_ms(10);				  //Giving the pulse to receive command.
	LCD_Command_Port &= ~(1<<E);  //
	_delay_ms(1);
	//second half of the command.
	LCD_Data_Port &=0x0F;
	LCD_Data_Port |= (cmd<<4);
	LCD_Command_Port |=  (1<<E);  //
	_delay_ms(10);				  //Giving the pulse to receive command.
	LCD_Command_Port &= ~(1<<E);  //
}
void LCD_cmd_4bits(char cmd)
{
	LCD_Command_Port &= ~(1<<RS); //RS to LOW to receive command.
	LCD_Data_Port = cmd;
	LCD_Command_Port |=  (1<<E);  //
	_delay_ms(10);				  //Giving the pulse to receive command.
	LCD_Command_Port &= ~(1<<E);  //
}
void LCD_init()
{
	LCD_Data_Dir |= ((1<<4)|(1<<5)|(1<<6)|(1<<7)); //DDRx for D4->D7 (put pins connected)
	LCD_Command_Dir |= ((1<<RS)|(1<<E)|(1<<RW));   //DDRx for RS,E,RW
	LCD_Command_Port &= ~(1<<RW);				   //RW to LOW to write on LCD.
	LCD_cmd_4bits(0x28);                           //4-bit mode.
	_delay_ms(10);
	LCD_cmd(0x01);								   //Clears LCD Screen.
	_delay_ms(10);
	LCD_cmd(0x80);								   //Put the cursor in the first line.
	_delay_ms(10);
	LCD_cmd(0x0C);                                 //Display ON, cursor OFF.
	//LCD_cmd(0x0E);                               //Display ON, cursor ON.
	_delay_ms(10);
}
void LCD_clear()
{
	_delay_ms(10);
	LCD_cmd(0x01); //Clears LCD Screen.
	_delay_ms(10);
}
void LCD_write_char(char data)
{
	LCD_Command_Port |= (1<<RS); //RS to HIGH to receive data.
	//First half of the command.
	LCD_Data_Port &=0x0F;
	LCD_Data_Port |= (0xF0&data);
	LCD_Command_Port |=  (1<<E);  //
	_delay_ms(10);				  //Giving the pulse to receive data.
	LCD_Command_Port &= ~(1<<E);  //
	_delay_ms(1);//second half of the command.
	LCD_Data_Port &=0x0F;
	LCD_Data_Port |= (data<<4);
	LCD_Command_Port |=  (1<<E);  //
	_delay_ms(10);				  //Giving the pulse to receive data.
	LCD_Command_Port &= ~(1<<E);  //
}
void LCD_write_str(char* str)
{
	for(int i=0;str[i] !='\0';i++)
	{
		LCD_write_char(str[i]);
	}
}
void LCD_goto_xy(int x,int y)
{
	if(x==1 && y<16)
	{
		LCD_cmd(0x80|y);
	}
	else if(x==2 && y<16)
	{
		LCD_cmd(0xC0|y);
	}
	else LCD_write_str("Out of dimension");
}
void LCD_write_int(int num)
{
	char str[10];
	itoa(num,str,10);
	LCD_write_str(str);
}
