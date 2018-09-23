#define F_CPU 100000UL
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

void interrupt_init()
{
cli();
GIFR|=(1<<INTF0); 
MCUCR|=(1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00);
GICR|=(1<<INT0)|(1<<INT1);
sei();
}

ISR (INT0_vect)
{
PORTB=0x00;
PORTA=0xFF;       
}

ISR (INT1_vect)
{   
	PORTA=0x00;
	PORTB=0xFF;
}

int main()
{
DDRB=0xFF;
DDRA=0xFF;
interrupt_init();
while(1);
}
