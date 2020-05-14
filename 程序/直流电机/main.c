#include <reg52.h>
#include <intrins.h>
#include <stdint.h>

sbit led_power=P0^0;
sbit led_run=P0^1;
sbit beef=P0^2;
sbit engine=P1^0;

//延时函数delay
void delay(int i)
{
    while(i--);
}

//主程序
void main()
{
long i;
long j;
led_power=0;
engine=0;

for(j=0;j<600;j++)
    {
        beef=~beef;
        delay(100);
    }


for(i=0;i<100;i++) //循环400次,大约18s
    {
        engine=1;
        led_run=0;
        delay(5000);  //一次约5ms
    }
engine=0;
led_run=1;

for(j=0;j<600;j++)
    {
        beef=~beef;
        delay(100);
    }   

while(1)
    {
    
    }
}