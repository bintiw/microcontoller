#ifndef __lcd_h
#define __lcd_h

#define rs PC0
#define rw PC2
#define en PC4
#define data PORTB

void lcd_init();
void lcd_cmd(char cmd_out);
void lcd_data(char data_out);
void lcd_str(char *str);
void shift_cmd(char cmd_in);
void shift_data(char data_in);

 void lcd_init()
 { shift_cmd(0X02);
   shift_cmd(0X28);
   shift_cmd(0X0C);
   shift_cmd(0X06);
   shift_cmd(0X83);
  } 


void shift_cmd(char cmd_in) 
 {char shift_data1;
  shift_data1= cmd_in & 0XF0;
  lcd_cmd(shift_data1);
   shift_data1= (cmd_in<<4) & 0XF0;
  lcd_cmd(shift_data1);
}

void lcd_cmd(char cmd_out)
{ data=cmd_out;
  PORTC=(0<<rs)|(0<<rw)|(1<<en);
  _delay_ms(10);
  PORTC=(0<<rs)|(0<<rw)|(0<<en);
  _delay_ms(10);
}


void shift_data(char data_in) 
 {char shift_data2;
  shift_data2= data_in & 0XF0;
  lcd_data(shift_data2);
   shift_data2= (data_in<<4) & 0XF0;
  lcd_data(shift_data2);
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
	 {shift_data(str[i]);
	  i++;
	  }
}

#endif 

