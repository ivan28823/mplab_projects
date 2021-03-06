#include "config.h"
#include "lcd.h"
#include "lcd_status.h"

void set_level(byte level){ //nivel del 0 a 15
	if(level >=0 && level <=15)     //solo admite valores desde 0-15
        for(byte i = 1;i<3;i++){	//ciclo para y 1,2
            lcd_gotoxy(1,i);		//ir a la posicion
            for(byte j = 0;j<16 ;j++)	//ciclo para x
                send_byte(DATA,i==1? (j<8? ' ' : j<=level? j-8: ' '):(j<8? (j<=level? j: ' '): (j<=level? 0x07: ' ')));
                //establece los valores para cada nivel
        }
}
void init_level(){	//para inicializar y preparar la lcd
    for (byte i = 0; i < 8; ++i)		//ciclo para establecer los caracteres
	  	set_sgram_byte(i,*(animation + i));	//ciclo para establecer un valor por cada posicion de la sgram
	set_level(0);						//establecemos en nivel 0 como inicio
}
