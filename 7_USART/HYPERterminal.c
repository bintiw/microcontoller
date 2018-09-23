#define F_CPU 8000000UL	
#define baud 9600	
#define value (((F_CPU / (baud * 16UL))) - 1)


#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define rs PC0
#define rw PC2
#define en PC4
#define data PORTB

void lcd_init();
void lcd_cmd(char cmd_out);
void lcd_data(char data_out);
void lcd_str(char *str);
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

 void lcd_init()
 { lcd_cmd(0X38);
   lcd_cmd(0X0C);
   lcd_cmd(0X06);
   lcd_cmd(0X80);
  } 

void usart_init()
{   
	UCSRB |= (1 << RXEN)|(1 << TXEN);   
	UCSRC |= (1 << URSEL) | (0<<USBS) | (1 << UCSZ0) | (1 << UCSZ1); 
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

void lcd_cmd(char cmd_out)
{ data=cmd_out;
  PORTC=(0<<rs)|(0<<rw)|(1<<en);
  _delay_ms(10);
  PORTC=(0<<rs)|(0<<rw)|(0<<en);
  _delay_ms(10);
}



void lcd_data(char data_out)
{ data=data_out;
  PORTC=(1<<rs)|(0<<rw)|(1<<en);
  _delay_ms(10);
  PORTC=(1<<rs)|(0<<rw)|(0<<en);
  _delay_ms(10);
}

void lcd_str(char *str)
 {unsigned int i=0;
    while(str[i]!='\0')
	 {lcd_data(str[i]);
	  i++;
	  }
}

void usart_send_str(char *str)
 {unsigned int i=0;
    while(str[i]!='\0')
	 {usart_send(str[i]);
	  i++;
	  }
}
   
