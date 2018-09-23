#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRD=0xFF;
while(1)
{
PORTD=0b00000010;
_delay_ms(3000);
PORTD=0b00000001;
_delay_ms(3000);

}

}
