#include <reg52.h>

sbit led_run=P0^1;

void delay(int i)
{
    while(i--);
}

void main()
{
    led_run=0;
    delay(50000);
    led_run=1;
    delay(50000);
}