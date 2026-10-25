#include<lpc214x.h>
void delay(void);
int main()
{
	PINSEL0=0X00000000;
	IO0DIR=0X00000180;//P0.4-O/P
	IO0CLR=0X00000180;
	while(1)
	{
		IO0SET=0X00000080; //p0.7=1
		IO0CLR=0X00000100;//P0.8=0
		delay();
		IO0SET=0X00000100;//P0.8=1
		IO0CLR=0X00000080;//p0.7=0
		delay();
	}
}
void delay(void)
{
	int i,j;
	for(i=0;i<300;i++)
	{
		for(j=0;j<300;j++)
		{
		}
	}
}