/*
 * MyLCD.h
 *
 * Created: 11-Oct-20 8:46:05 PM
 *  Author: moham
 */ 


#ifndef MYLCD_H_
#define MYLCD_H_

void LCD_cmd(char);        //To use LCD commands.
void LCD_cmd_4bits(char);
void LCD_init();		   //Initiate driver.
void LCD_clear();		   //Clears LCD.
void LCD_goto_xy(int,int); //Postion of the cursor on LCD
void LCD_write_char(char); //Write a char or a int.
void LCD_write_int(int); //Write a char or a int.
void LCD_write_str(char*); //Write a string.(char or int)

#endif /* MYLCD_H_ */