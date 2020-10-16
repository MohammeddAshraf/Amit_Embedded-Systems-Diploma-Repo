#include <avr/io.h>

//								PORTA
void InputPortA()
{
	DDRA = 0x00;
}
void OutputPortA()
{
	DDRA = 0xff;
}
void OutputPinA(int pin)
{
	DDRA |= (1<<pin);
}
void InputPinA(int pin)
{
	DDRA &= ~(1<<pin);
}
void setPinA(int pin)
{
	PORTA |= (1<<pin);
}
void resetPinA(int pin)
{
	PORTA &= ~(1<<pin);
}
void togglePinA(int pin)
{
	PORTA ^= (1<<pin);
}
int isPressedA(int pin)
{
	if(PINA & (1<<pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//								PORTB
void InputPortB()
{
	DDRB = 0x00;
}
void OutputPortB()
{
	DDRB = 0xff;
}
void OutputPinB(int pin)
{
	DDRB |= (1<<pin);
}
void InputPinB(int pin)
{
	DDRB &= ~(1<<pin);
}
void setPinB(int pin)
{
	PORTB |= (1<<pin);
}
void resetPinB(int pin)
{
	PORTB &= ~(1<<pin);
}
void togglePinB(int pin)
{
	PORTB ^= (1<<pin);
}
int isPressedB(int pin)
{
	if(PINB & (1<<pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//								PORTC
void InputPortC()
{
	DDRC = 0x00;
}
void OutputPortC()
{
	DDRC = 0xff;
}
void OutputPinC(int pin)
{
	DDRC |= (1<<pin);
}
void InputPinC(int pin)
{
	DDRC &= ~(1<<pin);
}
void setPinC(int pin)
{
	PORTC |= (1<<pin);
}
void resetPinC(int pin)
{
	PORTC &= ~(1<<pin);
}
void togglePinC(int pin)
{
	PORTC ^= (1<<pin);
}
int isPressedC(int pin)
{
	if(PINC & (1<<pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//								PORTD
void InputPortD()
{
	DDRD = 0x00;
}
void OutputPortD()
{
	DDRD = 0xff;
}
void InputPinD(int pin)
{
	DDRD &= ~(1<<pin);
}
void OutputPinD(int pin)
{
	DDRD |= (1<<pin);
}
void setPinD(int pin)
{
	PORTD |= (1<<pin);
}
void resetPinD(int pin)
{
	PORTD &= ~(1<<pin);
}
void togglePinD(int pin)
{
	PORTD ^= (1<<pin);
}
int isPressedD(int pin)
{
	if(PIND & (1<<pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
