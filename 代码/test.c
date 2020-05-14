#include <reg52.h>
#include <intrins.h>

sbit led_power=P0^0;
sbit led_run=P0^1;
sbit engine=P1^0;

void main(void)
{
led_power=0;
engine=1;
for(long i=0;i<18000000;i++);
engine=0;
led_run=1;
while(1);
}
