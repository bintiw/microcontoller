#ifndef _lcd_H
#define _lcd_H                                                  

#define rs 0x00020000
#define rw 0x00040000
#define en 0x00080000

void lcd_init(void);
void lcd_cmd(unsigned char);
void write_cmd(unsigned char);
void lcd_data(unsigned char);
void write_data(unsigned char);
void lcd_str(char *str);


void lcd_init()
{	IO1DIR = 0X00fe0000;
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
	lcd_cmd(0x80);
}
	
void lcd_str(char *str)
 {unsigned int i=0;
    while(str[i]!='\0')
	 {lcd_data(str[i]);
	  i++;
	  }
}

void lcd_cmd(unsigned char cmd)
{  
   write_cmd(cmd&0xf0);
	DelayMS(1);
	 write_cmd((cmd<<4)&0xf0);
	DelayMS(1);
}


void lcd_data(unsigned char data1)
{  write_data(data1&0xf0);
	DelayMS(1);
	 write_data((data1<<4)&0xf0);
	 DelayMS(1);
}

void write_cmd(unsigned char cmd)
{
  IO1CLR = 0x00fe0000;
	IO1SET = cmd<<16;
  IO1CLR = rs;
	IO1CLR = rw;
	IO1SET = en;
  DelayMS(1);
  IO1CLR = en;
  DelayMS(1);
	
}

void write_data(unsigned char data1)
{
  IO1CLR = 0x00fe0000;
	IO1SET = data1<<16;
  IO1SET = rs;
	IO1CLR = rw;
	IO1SET = en;
  DelayMS(1);
  IO1CLR = en;
  DelayMS(1);
	}

#endif
