
/* WHAT THE MAIN LOOKS LIKE

ISR(ADC_vect)
{
	int data;
	data = readADC();
	LCD_write_int(data*4.887585532746823); //5v reference.
	//LCD_write_int(data*2.932551319648094); //3v reference.
	_delay_ms(200);
	LCD_clear();
	ADC_Conv();
}

int main(void)
{
	LCD_init();
	ADC_(CH_1,AREF_MODE,PRE_128);
	sei();
	ADC_Conv();
	
	while (1)
	{
		
	}
}

*/

#include <avr/io.h>

void ADC_CH(int channelNo)
{
	if(channelNo<=7)				     //Reseting the channels to zero,keeping the frequency.
	{ADMUX = (ADMUX & 0xE0)|channelNo;}  //and Enable the required channel.
}
void ADC_Ref(int RefValue)
{
	ADMUX = (ADMUX & 0X3F)|(RefValue<<6); //Reset el Freq w keep channel w an2el el value set marat 3ashan awsal lel freq w a3del 3aleha
}
void ADC_Freq(int Prescaler)
{
	if(ADCSRA & (1<<ADIE))
	{
		ADCSRA &= ~(1<<ADIE);
		ADCSRA = (ADCSRA & 0xF8)|Prescaler;
		ADCSRA |= (1<<ADIE);
	}
	else
	{
		ADCSRA = (ADCSRA & 0xF8)|Prescaler;
	}
}
void ADC_Conv()
{
	ADCSRA |= (1<<ADSC); //Start analog to digital converting process.
}
void ADC_(int channelNo,int RefValue,int Prescaler)
{
	//Take sample
	ADC_CH(channelNo);   //from this channel
	ADC_Ref(RefValue);   //with this reference
	ADC_Freq(Prescaler); //at this frequency
	ADCSRA |= (1<<ADIE); //Enable ADC interrept.
	ADCSRA |= (1<<ADEN); //Enable the ADC port.
	
}

int readADC()
{
	//ADMUX |= (1<<ADLAR); //High mode.(ADCL->2),(ADCH->8)
	ADMUX &= ~(1<<ADLAR);  //Low mode.(ADCL->8),(ADCH->2)
	int val =ADCL;
	val |= (ADCH<<8);
	return val;
}

void Wait_ADC_Conv()
{
	while(!(ADCSRA & (1<<ADIF))); //Hanging
}