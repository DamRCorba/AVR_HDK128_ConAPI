

#ifndef DS1307_H_
#define DS1307_H_

#include "TWI_master.h"


void iniciar_reloj(unsigned char rs,unsigned char sqwe,unsigned char out);
void rtc_write(unsigned char address,unsigned char data);
unsigned char rtc_read(unsigned char address);
void leer_hora(unsigned char *hora,unsigned char *min,unsigned char *seg);
void escribir_hora(unsigned char hora,unsigned char min,unsigned char seg);
void leer_fecha(unsigned char *dia,unsigned char *mes,unsigned int *anio);
void escribir_fecha(unsigned char dia,unsigned char mes,unsigned char anio);

#endif /* DS1307_H_ */
