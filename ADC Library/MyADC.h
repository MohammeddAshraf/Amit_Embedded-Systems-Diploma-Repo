
#ifndef MYADC_H_
#define MYADC_H_

#define AVCC_MODE			1 //
#define AREF_MODE			0 //Reference modes.
#define INTERNAL_MODE		3 //

#define CH_0				0 //Channel 0
#define CH_1				1 //Channel 1
#define CH_2				2 //Channel 2
#define CH_3				3 //Channel 3
#define CH_4				4 //Channel 4
#define CH_5				5 //Channel 5
#define CH_6				6 //Channel 6
#define CH_7				7 //Channel 7

#define PRE_2				1 //Freq = T/2
#define PRE_4				2 //Freq = T/4
#define PRE_8				3 //Freq = T/8
#define PRE_16				4 //Freq = T/16
#define PRE_32				5 //Freq = T/32
#define PRE_64				6 //Freq = T/64
#define PRE_128				7 //Freq = T/128

void ADC_CH(int);
void ADC_Ref(int);
void ADC_Freq(int);
void ADC_Conv();
void ADC_(int,int,int);
int readADC();
void Wait_ADC_Conv();

#endif /* MYADC_H_ */