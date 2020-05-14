#include <reg52.h>
#include <intrins.h>

sbit led_power=P0^0;
sbit led_run=P0^1;
sbit beef=P0^2;
sbit engine=P1^0;

unsigned i;
void delay_microsecond(unsigned microsec)
{
    for (i = 0; i < microsec; i++);
    return;
}
void delay_millisecond(unsigned millisec)
{
    for (i = 0; i < millisec; i++)
        delay_microsecond(1000);
    return;
}
void delay_second(unsigned second)
{
    for (i = 0; i < second; i++)
        delay_millisecond(1000);
    return;
}    
void delay_minute(unsigned minute)    
{
    for (i = 0; i < minute; i++)
        delay_second(60);
    return;
}
void delay_hour(unsigned hour)
{
    for (i = 0; i < hour; i++)
        delay_minute(60);
    return;
}
void main()
{
int j;
led_power=0;
engine=0;

for(j=0;j<600;j++)
    {
        beef=~beef;
        delay_microsecond(100);
    }


engine=1;
led_run=0;
delay_second(20);
engine=0;
led_run=1;

for(j=0;j<600;j++)
    {
        beef=~beef;
        delay_microsecond(100);
    }   

while(1)
    {
    
    }
}