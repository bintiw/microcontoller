// This is a code to use a LCD in ATMEGA32
// Use proteus simulation file (.DSN) to see the operation

#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>

#define rs PC0
#define rw PC1
#define en PC2
#define data PORTD

uint16_t result;

void adc_init();
void lcd_init();
void lcd_cmd(char cmd_out);
void lcd_data(char data_out);
void lcd_str(char *str);
void view(uint16_t adxl);
void adc_con(int ch);

int main()
{DDRD=0XFF;
 DDRC=0XFF;
 lcd_init();
 adc_init();
 lcd_str("ADC VALUE::");
 while(1)
 {
 adc_con(7);
 }
 }

void adc_con(int ch) //ch is ADC channel
{ 
   ADMUX |= ch;	
  ADCSRA |=(1<<ADSC);
  while(!(ADCSRA&0x10)==0x10);	
  ADCSRA|=(1<<ADIF);	
  result=ADC;
  view(result);
}

void view(uint16_t adxl)
{ 
lcd_cmd(0xc6);
lcd_data((0x30+((adxl/1000)%10)));
lcd_data((0x30+((adxl/100)%10)));
lcd_data((0x30+((adxl/10)%10)));
lcd_data((0x30+(adxl%10)));
}  



void adc_init()		
{
	ADMUX |=(1<<REFS0);	
	ADCSRA|=(1<<ADEN)|(1<<ADPS1);	
}


void lcd_init()
 { lcd_cmd(0X38);
   lcd_cmd(0X0C);
   lcd_cmd(0X06);
   lcd_cmd(0X83);
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

   
