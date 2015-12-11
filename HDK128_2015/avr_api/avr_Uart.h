/*
 * avr_Uart.h
 *
 *  Created on: 2 de dic. de 2015
 *      Author: damian
 */

#ifndef AVR_API_AVR_UART_H_
#define AVR_API_AVR_UART_H_

#include "PeterFleury_AVRUART.h"


typedef enum{
avr_uart_port,
avr_uart1_port,
}UART_PORT_o;


typedef struct{
	unsigned long baudrate;
	UART_PORT_o   port;
}UartInitStructure_AVR;

void init_uart(UartInitStructure_AVR);

#define avr_uart_getc(port)   (port==avr_uart_port)?uart_getc():uart1_getc()
#define avr_uart_gets(port)   (port==avr_uart_port)?uart_gets():uart1_gets()
#define avr_uart_getc_p(port) (port==avr_uart_port)?uart_gets_p():uart1_gets_p()
#define avr_uart_gets_p(port) (port==avr_uart_port)?uart_gets_p():uart1_gets_p()

#define avr_uart_puts(port,dat) (port==avr_uart_port)?uart_puts(dat):uart1_puts(dat)
#define avr_uart_putc(port,dat) (port==avr_uart_port)?uart_putc(dat):uart1_putc(dat)
#define avr_uart_puts_p(port,dat) (port==avr_uart_port)?uart_puts_p(dat):uart1_puts_p(dat)
#define avr_uart_putc_p(port,dat) (port==avr_uart_port)?uart_putc_p(dat):uart1_putc_p(dat)

#endif /* AVR_API_AVR_UART_H_ */
