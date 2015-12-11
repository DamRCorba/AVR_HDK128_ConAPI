/*
 * HDK128_7SEGMENTOS.h
 *
 *  Created on: 5 de dic. de 2015
 *      Author: damian
 */

#ifndef HDK128_7SEGMENTOS_H_
#define HDK128_7SEGMENTOS_H_

#include "HDK128.h"

/******* DEFINICIONES PARA DISPLAY 7 SEGMENTOS ********/
//Utilizando IC 7511
#ifndef HDK128_H_
#include "avr_api/avr_api.h"

#define HDK128_7SEG_GPIO 		avr_GPIO_A
#define HDK128_7SEG_GPIO_OUT	avr_GPIOA_OUT

#define HDK128_7SEG_A			avr_GPIOA_OUT_0
#define HDK128_7SEG_A_PIN		avr_GPIO_PIN_0
#define HDK128_7SEG_B			avr_GPIOA_OUT_1
#define HDK128_7SEG_B_PIN		avr_GPIO_PIN_1
#define HDK128_7SEG_C			avr_GPIOA_OUT_2
#define HDK128_7SEG_C_PIN		avr_GPIO_PIN_2
#define HDK128_7SEG_D			avr_GPIOA_OUT_3
#define HDK128_7SEG_D_PIN		avr_GPIO_PIN_3

#define HDK128_DISP1			avr_GPIOA_OUT_4
#define HDK128_7SEG_DISP1_PIN	avr_GPIO_PIN_4
#define HDK128_DISP2			avr_GPIOA_OUT_5
#define HDK128_7SEG_DISP2_PIN	avr_GPIO_PIN_5
#define HDK128_DISP3			avr_GPIOA_OUT_6
#define HDK128_7SEG_DISP3_PIN	avr_GPIO_PIN_6
#define HDK128_DISP4			avr_GPIOA_OUT_7
#define HDK128_7SEG_DISP4_PIN	avr_GPIO_PIN_7

#define HDK128_7SEG_PUNTO_GPIO	avr_GPIO_G
#define HDK128_7SEG_PUNTO		avr_GPIOG_OUT_4
#define HDK128_7SEG_PUNTO_PIN	avr_GPIO_PIN_4

//Macro para escritura de display 7 Segmentos


/******************************************************/
#endif
#define HDK128_7SEG_DAT_OUT(macro_7seg_data) HDK128_7SEG_GPIO_OUT=(HDK128_7SEG_GPIO_OUT&0xF0)|(macro_7seg_data&0x0F)	//Macro para escribir el numero de a digitos en bcd

extern volatile unsigned int HDK128_7seg_numero;
extern volatile unsigned char HDK128_7seg_BarridoDisplay;
extern volatile unsigned char cronomero_centecima;

void HDK128_7SEG_init (void);
void HDK128_7SEG_Mostrar(unsigned int numero);
void HDK128_7seg_cronometro (void);


#endif /* HDK128_7SEGMENTOS_H_ */
