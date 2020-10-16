/*
 * My_Input_Output_Func.h
 *
 * Created: 28-Sep-20 9:52:15 PM
 *  Author: moham
 */ 


#ifndef MY_INPUT_OUTPUT_FUNC_H_
#define MY_INPUT_OUTPUT_FUNC_H_
//								PORTA
void InputPortA();
void OutputPortA();
void InputPinA(int pin);
void OutputPinA(int pin);
void setPinA(int pin);
void resetPinA(int pin);
void togglePinA(int pin);
int isPressedA(int pin);
//								PORTB
void InputPortB();
void OutputPortB();
void InputPinB(int pin);
void OutputPinB(int pin);
void setPinB(int pin);
void resetPinB(int pin);
void togglePinB(int pin);
int isPressedB(int pin);
//								PORTC
void InputPortC();
void OutputPortC();
void InputPinC(int pin);
void OutputPinC(int pin);
void setPinC(int pin);
void resetPinC(int pin);
void togglePinC(int pin);
int isPressedC(int pin);
//								PORTD
void InputPortD();
void OutputPortD();
void InputPinD(int pin);
void OutputPinD(int pin);
void setPinD(int pin);
void resetPinD(int pin);
void togglePinD(int pin);
int isPressedD(int pin);




#endif /* MY_INPUT_OUTPUT_FUNC_H_ */