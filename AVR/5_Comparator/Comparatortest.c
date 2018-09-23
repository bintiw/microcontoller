// This is a code to use Comparator function of ATMEGA32
// Use proteus simulation file (.DSN) to see the operation
#include<avr/io.h>
#include<util/delay.h>
void comp_init(void)
{
 ACSR=0x00;
}

void main()
{
 DDRD=0xFF;
 while(1)
{
  if((ACSR&0b00100000)==0b00100000)
   PORTD=0xFF;
   else
   PORTD=0x00;
}

}
