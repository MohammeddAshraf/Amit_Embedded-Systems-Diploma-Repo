#define F_CPU 16000000UL //Bafahem el delay el freq beta3ty kam.
#include <avr/io.h> //atmega32 library
#include <util/delay.h> //Delay library

#define Keypad_Pin_1 4     //Pin connected to 1
#define Keypad_Pin_2 5     //Pin connected to 2
#define Keypad_Pin_3 6     //Pin connected to 3
#define Keypad_Pin_A 0     //Pin connected to A
#define Keypad_Pin_B 1     //Pin connected to B
#define Keypad_Pin_C 2     //Pin connected to C
#define Keypad_Pin_D 3     //Pin connected to D
#define Keypad_DDRx  DDRA  //Keypad DDRx
#define Keypad_PORTx PORTA //Keypad PORTx
#define Keypad_PINx  PINA  //Keypad PINx
#define Keypad_delay 50    //Delay time between operations.

void Keypad_inti()
{
	Keypad_DDRx |=  ((1<<Keypad_Pin_1)|(1<<Keypad_Pin_2)|(1<<Keypad_Pin_3));                   // PA4,PA4,PA6 are outputs pins.
	Keypad_DDRx &= ~((1<<Keypad_Pin_A)|(1<<Keypad_Pin_B)|(1<<Keypad_Pin_C)|(1<<Keypad_Pin_D)); // Making PA0,1,2,3 input pins.
}
int getKeyPad()
{
	Keypad_PORTx |= ((1<<Keypad_Pin_1)|(1<<Keypad_Pin_2)|(1<<Keypad_Pin_3));				  // Setting PA4,5,6 to HIGH.

	if(Keypad_PINx & (1<<Keypad_Pin_A)) //Button is in row 1
	{
		Keypad_PORTx |= (1<<Keypad_Pin_1); 
		Keypad_PORTx &= ~((1<<Keypad_Pin_2)|(1<<Keypad_Pin_3)); //
		if(Keypad_PINx & (1<<Keypad_Pin_A)) {return 1;}			//Button is in row 1,column 1 i.e "Button 1"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_2); 
		Keypad_PORTx &= ~((1<<Keypad_Pin_3)|(1<<Keypad_Pin_1)); //
		if(Keypad_PINx & (1<<Keypad_Pin_A)) {return 2;}			//Button is in row 1,column 2 i.e "Button 2"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_3); 
		Keypad_PORTx &= ~((1<<Keypad_Pin_1)|(1<<Keypad_Pin_2)); //
		if(Keypad_PINx & (1<<Keypad_Pin_A)) {return 3;}			//Button is in row 1,column 3 i.e "Button 3"
		_delay_ms(Keypad_delay);								//
	}
	//Button is in row 2
	if(Keypad_PINx & (1<<Keypad_Pin_B))
	{
		Keypad_PORTx |= (1<<Keypad_Pin_1);
		Keypad_PORTx &= ~((1<<Keypad_Pin_2)|(1<<Keypad_Pin_3)); //
		if(Keypad_PINx & (1<<Keypad_Pin_B)) {return 4;}			//Button is in row 2,column 1 i.e "Button 4"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_2);
		Keypad_PORTx &= ~((1<<Keypad_Pin_3)|(1<<Keypad_Pin_1)); //
		if(Keypad_PINx & (1<<Keypad_Pin_B)) {return 5;}			//Button is in row 2,column 2 i.e "Button 5"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_3);
		Keypad_PORTx &= ~((1<<Keypad_Pin_1)|(1<<Keypad_Pin_2)); //
		if(Keypad_PINx & (1<<Keypad_Pin_B)) {return 6;}			//Button is in row 2,column 3 i.e "Button 6"
		_delay_ms(Keypad_delay);								//
	}
	//Button is in row 3
	if(Keypad_PINx & (1<<Keypad_Pin_C))
	{
		Keypad_PORTx |= (1<<Keypad_Pin_1);
		Keypad_PORTx &= ~((1<<Keypad_Pin_2)|(1<<Keypad_Pin_3)); //
		if(Keypad_PINx & (1<<Keypad_Pin_C)) {return 7;}			//Button is in row 3,column 1 i.e "Button 7"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_2);
		Keypad_PORTx &= ~((1<<Keypad_Pin_3)|(1<<Keypad_Pin_1)); //
		if(Keypad_PINx & (1<<Keypad_Pin_C)) {return 8;}			//Button is in row 3,column 2 i.e "Button 8"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_3);
		Keypad_PORTx &= ~((1<<Keypad_Pin_1)|(1<<Keypad_Pin_2)); //
		if(Keypad_PINx & (1<<Keypad_Pin_C)) {return 9;}			//Button is in row 3,column 3 i.e "Button 9"
		_delay_ms(Keypad_delay);								//
	}
	//Button is in row 4
	if(Keypad_PINx & (1<<Keypad_Pin_D))
	{
		Keypad_PORTx |= (1<<Keypad_Pin_1);
		Keypad_PORTx &= ~((1<<Keypad_Pin_2)|(1<<Keypad_Pin_3)); //
		if(Keypad_PINx & (1<<Keypad_Pin_D)) {return 0;}			//Button is in row 4,column 1 i.e "Button *"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_2);
		Keypad_PORTx &= ~((1<<Keypad_Pin_3)|(1<<Keypad_Pin_1)); //
		if(Keypad_PINx & (1<<Keypad_Pin_D)) {return 0;}			//Button is in row 4,column 2 i.e "Button 0"
		_delay_ms(Keypad_delay);								//
		
		Keypad_PORTx |= (1<<Keypad_Pin_3);
		Keypad_PORTx &= ~((1<<Keypad_Pin_1)|(1<<Keypad_Pin_2)); //
		if(Keypad_PINx & (1<<Keypad_Pin_D)) {return 0;}			//Button is in row 4,column 3 i.e "Button #"
		_delay_ms(Keypad_delay);							    //
	}
	return '-';
}