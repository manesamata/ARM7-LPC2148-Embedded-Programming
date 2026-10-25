#include<lpc214x.h>
void PLL0(void);
void UART_init(void);
void trans(unsigned char);
unsigned char receive(void);
void UART_string(unsigned char *);
void delay(void);

int main()
{
	unsigned char x;
	UART_init();
	PLL0();
	IO0DIR=0X00000010; //LED AT P0.4
	IO0CLR=0X00000010;
	while(1)
	{
		x=receive();
		trans(x);
		if(x=='A')
		{
			UART_string("led is ON\r\n");
			IO0SET=0X00000010;
		}
		else if(x=='B')
		{
			IO0CLR=0X00000010;
			UART_string("led is OFF\r\n");
		}
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
unsigned char receive(void)
{
	while((U0LSR&(1<<0))==0);
	return U0RBR;
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