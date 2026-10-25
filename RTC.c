#include<lpc214x.h>
#include"LCD.h"
void RTC_init(void);
int main()
{
	lcd_init();
	lcd_string("RTC INTERFACE");
	RTC_init();
	while(1)
	{
		lcd_cmd(0XC0);
		lcd_data((HOUR/10)+'0');
		lcd_data((HOUR%10)+'0');
		lcd_data(':');
		lcd_data((MIN/10)+'0');
		lcd_data((MIN%/10)+'0');
		lcd_data(':');
		lcd_data((SEC/10)+'0');
		lcd_data((SEC%10)+'0');
	}
}
void RTC_init(void)
{
	ILR=0X01;
	CCR=0X13;
	CCR=0X11;
	SEC=0;
	MIN=21;
	HOUR=14;
}
