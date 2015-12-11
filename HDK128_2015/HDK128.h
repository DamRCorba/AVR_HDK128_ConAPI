/*
 * HDK128.h
 *
 *  Created on: 29 de nov. de 2015
 *      Author: Ingeniero Damian Ruben Corbalan
 *      Brief:  Archivo de configuracion de placa HDK128
 */

#ifndef HDK128_H_
#define HDK128_H_
#include "avr_api/avr_api.h"


/******* DEFINICIONES PARA DISPLAY 7 SEGMENTOS ********/
//Utilizando IC 7511
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



/******************************************************/


/**************** DEFINICIONES PARA LEDs ***************/
#define LED_1_GPIO_PORT			avr_GPIO_D
#define LED_1_GPIO_PIN			avr_GPIO_PIN_4
#define LED_1					avr_GPIOD_OUT_4

#define LED_2_GPIO_PORT			avr_GPIO_D
#define LED_2_GPIO_PIN			avr_GPIO_PIN_5
#define LED_2					avr_GPIOD_OUT_5

#define LED_3_GPIO_PORT			avr_GPIO_D
#define LED_3_GPIO_PIN			avr_GPIO_PIN_6
#define LED_3					avr_GPIOD_OUT_6

#define LED_4_GPIO_PORT			avr_GPIO_D
#define LED_4_GPIO_PIN			avr_GPIO_PIN_7
#define LED_4					avr_GPIOD_OUT_7
/*******************************************************/

/**************** DEFINICIONES PARA PULSADORES ***************/
#define SW1_GPIO_PORT			avr_GPIO_E
#define SW1_GPIO_PIN			avr_GPIO_PIN_5
#define SW1						avr_GPIOE_IN_5
#define SW1_IRQ					avr_INT5

#define SW2_GPIO_PORT			avr_GPIO_E
#define SW2_GPIO_PIN			avr_GPIO_PIN_6
#define SW2						avr_GPIOE_IN_6
#define SW2_IRQ					avr_INT6

#define SW3_GPIO_PORT			avr_GPIO_E
#define SW3_GPIO_PIN			avr_GPIO_PIN_7
#define SW3						avr_GPIOE_IN_7
#define SW3_IRQ					avr_INT7
/*************************************************************/

/************ DISPLAY LCD ************/		//Definiciones para utilizar la libreria
#define RS_LCD			0
#define RD_LCD			1
#define	EN_LCD			2
#define D4_LCD			4
#define	D5_LCD			5
#define	D6_LCD			6
#define	D7_LCD			7
#define DIR_LCD			avr_GPIOC_DIR
#define PUERTO_LCD_OUT	avr_GPIOC_OUT
#define BLGT			avr_GPIOG_OUT_2
#define BLGT_DIR		avr_GPIOG_DIR_2
/*************************************/

/***********POTENCIOMETRO*************/
#define	HDK128_POTENCIOMETRO avr_ADC_canal3
/*************************************/

/*************** LM35 *****************/
#define	HDK128_LM35 avr_ADC_canal2
/**************************************/

void SW1_handler(void);
void SW2_handler(void);
void SW3_handler(void);
void mysystick_handler(void);


extern volatile unsigned int base_tiempo;
extern volatile unsigned int tiempo_l1;
extern volatile unsigned int tiempo_l2;
extern volatile unsigned int tiempo_l3;
extern volatile unsigned int tiempo_l4;

#include "HDK128_7SEGMENTOS.h"

#endif /* HDK128_H_ */
