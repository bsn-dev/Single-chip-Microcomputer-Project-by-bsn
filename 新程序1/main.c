#include <reg52.h>

sbit led_power=P0^0;
sbit led_run=P0^1;

void Timer0Init()
{
    TMOD|=0X01;
    TH0=0XFC;
    TL0=0X18;
    ET0=1;
    EA=1;
    TR0=1;
}

void main()
{
    led_power=0;
    Timer0Init();
    while(1)
}

void Time0() interrupt 1
{
    int i;
    TH0=0XFC;
    TL0=0X18;
    i++;
    if(i==1000)
    {
        i=0;
        led_run=~led_run;
    }
}