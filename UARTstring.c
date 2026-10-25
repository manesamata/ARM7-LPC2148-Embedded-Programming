#include<lpc214x.h>
void PLL0(void);
void UART_init(void);
void trans(unsigned char);
void UART_string(unsigned char *);
void delay(void);

int main()
{
	PLL0();
	UART_init();
	while(1)
	{
		UART_string("HELLO\r\n");
		delay();
	}
}
void UART_init(void)
{
	PINSEL0=0X00000005;
	U0LCR=0X80;
	U0DLL=0X61;
	U0DLM=0X00;
	U0FDR=0X00000010;
	U0LCR=0X03;
	U0FCR=0X07;
}
void trans(unsigned char x)
{
	U0THR=x;
	while((U0LSR&(1<<5)==0));
}
void UART_string(unsigned char *p)
{
	while(*p!='\0')
	{
		trans(*p);
		p++;
	}
}
void delay(void)
{
	int a,b,c;
	{
		for(a=0;a<200;a++)
		{
			for(b=0;b<200;b++)
			{
				for(c=0;c<200;c++)
				{
				}
			}
		}
	}
}
void PLL0(void)
{
	PLL0CON=0X01;
	PLL0CFG=0X24;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
	while((PLL0STAT&(1<<10))==0);
	PLL0CON=0X03;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
	VPBDIV=0X00;
}
