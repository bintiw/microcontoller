// This is a code to blink led connected to one of the pin in PORTC depending on the status of switch for ATMEGA32
// Use proteus simulation file (.DSN) to see the operation
#define F_CPU 1000000UL

#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRC=0b00000010;

while(1)

{
  if((PINC&0b00000001)==0b00000001)
    {PORTC=0b00000010;
	_delay_ms(10);
	PORTC=0b00000000;
	_delay_ms(10);}
	
	else
	{PORTC=0b00000010;
	_delay_ms(200);
	PORTC=0b00000000;
	_delay_ms(200);}
	
}


}
