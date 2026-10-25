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
	}
}