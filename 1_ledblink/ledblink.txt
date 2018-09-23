#define F_CPU 1000000UL

#include<avr/io.h>
#include<util/delay.h>

int main()
{ 
 DDRD=0xFF;
 
  
 while(1)
 { 
   PORTD=0b00001111;
   _delay_ms(1000);
   PORTD=0b11110000;
   _delay_ms(1000);
   PORTD=0xFF;
   _delay_ms(1000);
   PORTD=0x00;
   _delay_ms(1000);
 
}
}
