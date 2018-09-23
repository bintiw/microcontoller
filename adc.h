#ifndef __adc_h
#define __adc_h


uint16_t result;

void adc_init();
void view(uint16_t adxl);
void adc_con(int ch);


void adc_con(int ch)
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

   
#endif