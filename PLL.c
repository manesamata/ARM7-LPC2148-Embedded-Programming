#include<lpc214x.h>
void PLL0(void);
int main()
{
	PLL0();
	while(1)
	{
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