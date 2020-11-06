/*
 * MyTimer.h
 *
 * Created: 29-Oct-20 12:06:54 PM
 *  Author: Mohammed Ashraf
 */ 


#ifndef MYTIMER_H_
#define MYTIMER_H_
//Timer source

#define TimerOFF			0
#define Internal_0			1
#define Internal_8			2
#define Internal_64			3
#define Internal_256		4
#define Internal_1024		5
#define External_Failling	6
#define External_Rising		7

//Timer mode

#define Normal		0x00
#define CTC			0x08
#define FPWM		0x48
#define PWM			0x40

//OC0 modes

#define OC0_DutyCycle		25
#define OC0_OFF				0

#define OC0_CTC_TOGGLE		1
#define OC0_CTC_CLEAR		2
#define OC0_CTC_SET			3

#define OC0_FPWM_CLEARonCompare			2
#define OC0_FPWM_SETonCompare			3

#define OC0_PWM_CLEARonCompare			2
#define OC0_PWM_SETonCompare			3

//Timer0 Enable

#define TOV_INT			0
#define TOC_INT			1
#define TIMER_INT_OFF	3

///////////////////////////////////////////////////////////////

void Timer0_ClkSource(int);
void Timer0_Mode(int);
void Timer0_OC0_Mode(int);
void Timer0_Interrupt(int);
void Timer_OC0_DutyCycle(int DutyCycle);
void Timer0_init(int,int,int,int);

#endif /* MYTIMER_H_ */