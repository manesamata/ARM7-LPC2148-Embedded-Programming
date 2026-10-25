#include<lpc214x.h>
int main()
{
	PINSEL0=0X00000000;
	IO0DIR=0X00000040;
	IO0CLR=0X00000040;
	while(1)
	{
		if((IO0PIN&0X00000200)==0)
		{
			IO0SET=0X00000040;
		}
		else
		{
			IO0CLR=0X00000040;
		}
	}
}
		