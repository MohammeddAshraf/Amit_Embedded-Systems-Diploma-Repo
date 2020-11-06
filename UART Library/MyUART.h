

#ifndef MYUART_H_
#define MYUART_H_

void UART_init();
void UART_Send_Char(char);
void UART_Send_Num(int);
void UART_Send_Str(char*);
char UART_Receive();


#endif /* MYUART_H_ */