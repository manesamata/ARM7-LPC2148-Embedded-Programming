#include<lpc214x.h>
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(void);

int main()
{
	lcd_init();
	lcd_data('H');
	lcd_data('E');
	lcd_data('L');
	lcd_data('L');
	lcd_data('O');
	while(1)
	{
	}
}
void lcd_init(void)
{
	PINSEL1=0X00000000;
	IO0DIR=0X00FF0000;
	IO0DIR|=(1<<13)|(1<<14)|(1<<15);
	lcd_cmd(0X30);
	lcd_cmd(0X38);
	lcd_cmd(0X01);
	lcd_cmd(0X80);
	lcd_cmd(0X0F);
}
void lcd_cmd(unsigned char c)
{
	IO0CLR=0X00FF0000;
	IO0SET|=(c<<16);
	IO0CLR|=(1<<13); //RS=0
	IO0CLR|=(1<<14); //RW=0
	IO0SET|=(1<<15); //EN=1
	delay();
	IO0CLR|=(1<<15); //EN=0
}
void lcd_data(unsigned char c)
{
	IO0CLR=0X00FF0000;
	IO0SET|=(c<<16);
	IO0SET|=(1<<13); //RS=1
	IO0CLR|=(1<<14); //RW=0
	IO0SET|=(1<<15); //EN=1
	delay();
	IO0CLR|=(1<<15); //EN=0
}
void delay(void)
{
	int i,j;
	for(i=0;i<200;i++)
	{
		for(j=0;j<200;j++)
		{
		}
	}
}


	