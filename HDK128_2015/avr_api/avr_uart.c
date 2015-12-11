/*
 * avr_uart.c
 *
 *  Created on: 2 de dic. de 2015
 *      Author: damian
 */

#include "avr_Uart.h"


/*
 *  In
 */
void init_uart(UartInitStructure_AVR _avr_uart){
	switch (_avr_uart.port) {
		case avr_uart1_port:
			uart1_init(UART_BAUD_SELECT(_avr_uart.baudrate,F_CPU));
			break;
		case avr_uart_port:
			uart_init(UART_BAUD_SELECT(_avr_uart.baudrate,F_CPU));
			break;
		default:
			break;
	}
}
