#include<lpc214x.h>
void delay(void);
int main()
{
	PINSEL0=0X00000000;
	IO0DIR=0X00000010;//P0.4-O/P
	IO0CLR=0X00000010;
	while(1)
	{
		IO0SET=0X00000010; //p0.4-1
		delay();
		IO0CLR=0X00000010;//p0.4-0
		delay();
	}
}
void delay(void)
{
	T0CTCR=0X00;
	T0TCR=0X03;
	T0PR=0X10000000;
	T0TCR=0X01;
	while(T0TC<12);
	T0TCR=0X00;
}