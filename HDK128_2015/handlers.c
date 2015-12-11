/*
 * botones.c
 *
 *  Created on: 29 de nov. de 2015
 *      Author: damian
 */


#include "HDK128.h"

void SW1_handler(void){
	LED_1 = 0;
	LED_2 = 1;
	LED_3 = 1;
	LED_4 = 1;
	HDK128_7seg_numero = 0;
}


void SW2_handler(void){
	LED_1 = 1;
	LED_2 = 0;
	LED_3 = 1;
	LED_4 = 1;

}

void SW3_handler(void){
	LED_1 = 1;
	LED_2 = 1;
	LED_3 = 0;
	LED_4 = 1;

}

volatile unsigned int base_tiempo = 0;
volatile unsigned int tiempo_l1 = 0;
volatile unsigned int tiempo_l2 = 0;
volatile unsigned int tiempo_l3 = 0;
volatile unsigned int tiempo_l4 = 0;


void mysystick_handler(void){
	base_tiempo++;
	tiempo_l1++;
	tiempo_l2++;
	tiempo_l3++;
	tiempo_l4++;
	HDK128_7seg_cronometro();
}
