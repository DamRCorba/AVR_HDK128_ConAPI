/*
 * HDK128_7SEGMENTOS.c
 *
 *  Created on: 5 de dic. de 2015
 *      Author: damian
 */

#include "HDK128_7SEGMENTOS.h"

volatile unsigned int HDK128_7seg_numero = 0;
volatile unsigned char HDK128_7seg_BarridoDisplay = 0;
volatile unsigned char cronomero_centecima=0;

/*
 * Funcion de muestra de numeros en display
 */
void HDK128_7SEG_Mostrar(unsigned int numero){
    int u,d,c,udm;
    udm=numero/1000;
    c= (float)numero/100-(float)(10*(float)udm);
    d= (float)numero/10-(float)((float)c*10)-(float)((float)udm*100);
    u = (float)numero-(float)((float)d*10)-(float)((float)c*100)-(float)((float)udm*1000);


    switch (HDK128_7seg_BarridoDisplay) {

	case 0:
		    HDK128_DISP1 = 1;
		    HDK128_DISP2 = 0;
		    HDK128_DISP3 = 0;
		    HDK128_DISP4 = 0;
		    HDK128_7SEG_DAT_OUT((unsigned char)udm);
		    HDK128_7SEG_PUNTO = 0;

		    break;
	case 1:
			HDK128_DISP1 = 0;
			HDK128_DISP2 = 1;
			HDK128_DISP3 = 0;
			HDK128_DISP4 = 0;
			HDK128_7SEG_DAT_OUT(c);
			HDK128_7SEG_PUNTO = 1;
		    break;
	case 2:
			HDK128_DISP1 = 0;
			HDK128_DISP2 = 0;
			HDK128_DISP3 = 1;
			HDK128_DISP4 = 0;
			HDK128_7SEG_DAT_OUT(d);
			HDK128_7SEG_PUNTO = 0;
		    break;
	case 3:
			HDK128_DISP1 = 0;
			HDK128_DISP2 = 0;
			HDK128_DISP3 = 0;
			HDK128_DISP4 = 1;
			HDK128_7SEG_DAT_OUT(u);
			HDK128_7SEG_PUNTO = 0;
		    break;

	default:    HDK128_7seg_BarridoDisplay = 0;
		    break;
    }

}

/*
 * Funcion que debe ser llamada cada 1 mseg y mostrara en un display 7 segmentos
 * manejado por un IC 7815 + Transistores habilitadores un cronometro de 1 min
 */

void HDK128_7seg_cronometro(void){
		HDK128_7SEG_Mostrar(HDK128_7seg_numero);
		if(cronomero_centecima++>10)		//aumenta numero cada 10mSeg
				{
		    	cronomero_centecima =0;
				HDK128_7seg_numero= (HDK128_7seg_numero < 5999) ? HDK128_7seg_numero+1 : 0;
				}
		HDK128_7seg_BarridoDisplay=(HDK128_7seg_BarridoDisplay<3)?HDK128_7seg_BarridoDisplay+1:0;
}

/*
 *  Funcion de Inicializacion del Display 7 Segmentos
 */

void HDK128_7SEG_init (void){
	GpioInitStructure_AVR display7seg;
	display7seg.modo = avr_GPIO_mode_Output;
	display7seg.port = HDK128_7SEG_GPIO;
	display7seg.pines = HDK128_7SEG_A_PIN | HDK128_7SEG_B_PIN |HDK128_7SEG_C_PIN | HDK128_7SEG_D_PIN
						| HDK128_7SEG_DISP1_PIN |HDK128_7SEG_DISP2_PIN| HDK128_7SEG_DISP3_PIN |HDK128_7SEG_DISP4_PIN;
	init_gpio(display7seg);

	display7seg.port = HDK128_7SEG_PUNTO_GPIO;
	display7seg.pines = HDK128_7SEG_PUNTO_PIN;
	init_gpio(display7seg);

}
