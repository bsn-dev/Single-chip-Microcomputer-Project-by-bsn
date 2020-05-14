#include <reg52.h>
#include <intrins.h>

sbit led_power=P0^0;
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
led_power=0;
engine=0;
for(i=0;i<400;i++) //??400?,?????20s
{
    engine=1;
    delay(5000);  //????????5ms
}
engine=0;
while(1)
{

}
}