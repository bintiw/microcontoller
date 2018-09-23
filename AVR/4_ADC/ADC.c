// This is a code to light led connected to PORTC of ATMEGA32 according to the ADC conversion
// Use proteus simulation file (.DSN) to see the operation

#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>

uint16_t x1;
void adc_init()		
{	
	ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADATE);	
	SFIOR=0x00;					
}


unsigned int adc_conv( unsigned char ch)
{
  
 ADMUX |= (ch & 0b00000111);
 ADMUX |= (1<<REFS0);
 while(!(ADCSRA & (1<<ADIF)));	
 ADCSRA|=(1<<ADIF);
 return(ADC);
}


int main()
{
DDRC=0XFF;
adc_init(); 
while(1)
{
x1=adc_conv(0);
PORTC=x1;
}

}
