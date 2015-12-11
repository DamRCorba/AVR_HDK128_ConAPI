
#include "DS1307.h"

void iniciar_reloj(unsigned char rs,unsigned char sqwe,unsigned char out)
{
	rs&=3;
	if (sqwe) rs|=0x10;
	if (out) rs|=0x80;
	twi_start_cond();
	i2c_write_byte(0xd0);
	i2c_write_byte(7);
	i2c_write_byte(rs);
	twi_stop_cond();
}
void rtc_write(unsigned char address,unsigned char data)
{
	twi_start_cond();
	i2c_write_byte(0xD0);
	i2c_write_byte(address);
	i2c_write_byte(data);
	twi_stop_cond();
}
unsigned char rtc_read(unsigned char address)
{
	unsigned char data;
	twi_start_cond();
	i2c_write_byte(0xD0);
	i2c_write_byte(address);
	twi_stop_cond();
	twi_start_cond();
	i2c_write_byte(0xD1);
	data=i2c_read_byte2(0);
	twi_stop_cond();
	return data;
}
void leer_hora(unsigned char *hora,unsigned char *min,unsigned char *seg)
{
		unsigned char registro;

		twi_start_cond();	
		i2c_write_byte(0xD0);	
		i2c_write_byte(0);
		twi_stop_cond();
		twi_start_cond();
		i2c_write_byte(0xD1);
		registro=i2c_read_byte2(1);
		*seg=((registro&0x70)>>4)*10 + (registro&0x0F);
    	registro=i2c_read_byte2(1);        
    	*min=((registro&0x70)>>4)*10 + (registro&0x0F);
		registro=i2c_read_byte2(0);
		*hora=((registro&0x30)>>4)*10 + (registro&0x0F);
		twi_stop_cond();
}
void escribir_hora(unsigned char hora,unsigned char min,unsigned char seg)
{
	unsigned char registro;

	twi_start_cond();
	i2c_write_byte(0xD0);
	i2c_write_byte(0);
	registro = seg/10;
	i2c_write_byte((registro<<4)|(seg-registro*10));
	registro = min/10;
	i2c_write_byte((registro<<4)|(min-registro*10));
	registro = hora/10;
	i2c_write_byte((registro<<4)|(hora-registro*10));
	twi_stop_cond();
}
void leer_fecha(unsigned char *dia,unsigned char *mes,unsigned *anio)
{
	unsigned char registro;

	twi_start_cond();
	i2c_write_byte(0xD0);
	i2c_write_byte(4);
	twi_stop_cond();
	twi_start_cond();
	i2c_write_byte(0xD1);
	registro=i2c_read_byte2(1);
	*dia=((registro&0x70)>>4)*10 + (registro&0x0F);
	registro=i2c_read_byte2(1);
	*mes=((registro&0x70)>>4)*10 + (registro&0x0F);
	registro=i2c_read_byte2(0);
	*anio=((registro&0x30)>>4)*10 + (registro&0x0F);
	twi_stop_cond();

}
void escribir_fecha(unsigned char dia,unsigned char mes,unsigned char anio)
{
	unsigned char registro;

	twi_start_cond();
	i2c_write_byte(0xD0);
	i2c_write_byte(4);
	registro = dia/10;
	i2c_write_byte((registro<<4)|(dia-registro*10));
	registro = mes/10;
	i2c_write_byte((registro<<4)|(mes-registro*10));
	registro = anio/10;
	i2c_write_byte((registro<<4)|(anio-registro*10));
	twi_stop_cond();
}

