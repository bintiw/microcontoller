#define F_CPU 8000000UL	
#define baud 9600	
#define value (((F_CPU / (baud * 16UL))) - 1)


#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<lcd.h>

void usart_init();
void usart_read();
void usart_send(char datam);
void usart_send_str(char *str);

int main()
{ 
 DDRB=0XFF;
 DDRC=0XFF;
 lcd_init(); 
 usart_init();
 usart_send_str("hello USART"); 
 while(1)
 {
     usart_read();
 }
 }



void usart_init()
{   
	UCSRB |= (1 << RXEN)|(1 << TXEN);   
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); 
    UBRRL = value; 
}



void usart_read()
{   
    while ((UCSRA & (1 << RXC)) == 0); 
	lcd_data(UDR);
}



void usart_send(char datam)
{ while(!(UCSRA & (1 << UDRE)));   
   UDR = datam; 
 }



void usart_send_str(char *str)
 {unsigned int i=0;
    while(str[i]!='\0')
	 {usart_send(str[i]);
	  i++;
	  }
}
   
