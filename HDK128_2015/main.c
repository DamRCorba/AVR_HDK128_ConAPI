/*
 * main.c
 *
 *  Created on: 29 de nov. de 2015
 *      Author: Ing. Damian Corbalan
 *      brief: Programa de ejemplo para el uso de la API
 *      	   ejemplo de manejo de puertos.
 *      	   La presente copilacion de ejemplos se hace sobre la placa HDK128
 *      	   desarrollada en el Laboratorio Abierto de la UTN FRA
 *
 */

#include "HDK128.h"
#include "lcd_alfa.h"
#include "DS1307.h"
#include <stdio.h>


//Programa de ejemplo para manejo de puertos
int main(void) {
	GpioInitStructure_AVR leds, pulsadores;
	ExternalInterruptInitStructure_AVR pulsadores_irq;
	SystickInitStructure_AVR base;
	AdcInitStructure_AVR potenciometro;
	unsigned char hora, min, seg;
	unsigned char dia, mes;
	unsigned anio;
	char cadena_hora[]="18:06:00";
	char cadena_fecha[]="10/12/15";
    char salida_txt[20];
	UartInitStructure_AVR com0;



	// Inicializamos puerto de led como salida
	leds.modo = avr_GPIO_mode_Output;
	leds.port = LED_1_GPIO_PORT; // es el mismo puerto para todos los leds.
	leds.pines = LED_1_GPIO_PIN | LED_2_GPIO_PIN | LED_3_GPIO_PIN | LED_4_GPIO_PIN;
	init_gpio(leds);

	//Inicializamos puerto de pulsadores como entrada
	pulsadores.modo = avr_GPIO_mode_Input;
	pulsadores.port = SW1_GPIO_PORT; // Mismo puerto para todos los pulsadores
	pulsadores.pines = SW1_GPIO_PIN | SW2_GPIO_PIN | SW3_GPIO_PIN;
	init_gpio(pulsadores);

	//Inicializamos interrupciones externas
//	pulsadores_irq.modo = avr_ext_int_lowlevel;
//	pulsadores_irq.interrupcion= SW1_IRQ;
//	pulsadores_irq.avr_ext_interrupt_handler=SW1_handler;
//	init_extern_interrupt(pulsadores_irq);

	//Inicializamos interrupciones externas
	pulsadores_irq.modo = avr_ext_int_lowlevel;
	pulsadores_irq.interrupcion= SW2_IRQ;
	pulsadores_irq.avr_ext_interrupt_handler=SW2_handler;
	init_extern_interrupt(pulsadores_irq);

	//Inicializamos interrupciones externas
	pulsadores_irq.modo = avr_ext_int_lowlevel;
	pulsadores_irq.interrupcion= SW3_IRQ;
	pulsadores_irq.avr_ext_interrupt_handler=SW3_handler;
	init_extern_interrupt(pulsadores_irq);


	//Inicializamos timer para base de tiempo
	base.time_ms = 1; // salta cada 1 milisegundo
	base.timernumber = avr_TIM2;
	base.avr_systick_handler= mysystick_handler;
	init_Systick_timer(base);

	potenciometro.mode=avr_ADC_MODE_Single_Conversion;
	potenciometro.channel= HDK128_POTENCIOMETRO;
	potenciometro.prescaler= avr_ADC_Prescaler_64;
	potenciometro.resolution = avr_ADC_RES_10Bit;
	potenciometro.reference = avr_ADC_REF_AVcc;
	init_adc(potenciometro);

	HDK128_7SEG_init();

	twi_init();				//Configura TWI para controlar integrado de reloj
	iniciar_reloj(0,1,0);		//
	escribir_fecha(10,12,15);		//
	escribir_hora(18,06,0);		//

	com0.baudrate=9600;
	com0.port=avr_uart_port;
	init_uart(com0);
	com0.port=avr_uart1_port;
	init_uart(com0);

	//c=avr_uart_getc(avr_uart_port); // ver de implementar otras librerias para uart.
	//Inicializamos interrupciones globales
	sei();

	lcd_init(LCD_DISP_ON); 				//Inicializacion del Display LCD 16 x 2
	BLGT_DIR =1;					//Configura el pin del backlight como salida
	BLGT =1;						//prende el backlight

	lcd_gotoxy(1,0);
	lcd_puts("AVR_API HDK128");
	lcd_gotoxy(2,1);
	lcd_puts("V.POTE = ");

	while(1){

		if(tiempo_l1>100)
		{
			LED_1 ^=1;
			tiempo_l1=0;
		}

		if(tiempo_l2>200)
			{
				LED_2 ^=1;
				tiempo_l2=0;
			}

		if(tiempo_l3>300)
			{
				LED_3 ^=1;
				tiempo_l3=0;
			}

		if(tiempo_l4>1000)
			{
				LED_4 ^=1;
				tiempo_l4=0;

			    sprintf(salida_txt,"Temp = %03d \n\r",leer_ADC(HDK128_LM35));
			    avr_uart_puts(avr_uart_port,salida_txt);

			    leer_hora(&hora,&min,&seg);
			    sprintf(cadena_hora,"%02d:%02d:%02d\n\r",hora,min,seg);
			    avr_uart_puts(avr_uart1_port,cadena_hora);

			    leer_fecha(&dia,&mes,&anio);
			    sprintf(cadena_fecha,"%02d/%02d/%02d\n\r",dia,mes,anio);
			    avr_uart_puts(avr_uart1_port,cadena_fecha);

			}

		if(!SW1){
			HDK128_7seg_numero = 0;
		}

		lcd_gotoxy(11,1);
		sprintf(salida_txt,"%d ",leer_ADC(HDK128_POTENCIOMETRO)); //leer_adc devuelve el valor convertido del canal seleccionado
		lcd_puts(salida_txt);



	}

	return 1;

}



