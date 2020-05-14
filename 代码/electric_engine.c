//单片机大作业——直流电机程序
#include <reg52.h>
#include <intrins.h>

sbit engine=P1^0

//延时函数delay
void delay(int i)
{
    while(i--);
}

//主程序
void main()
{
long i;
engine=0;
for(i=0;i<400;i++) //循环400次，计算得大约20s
{
    engine=1;
    delay(5000);  //根据芯片频率大约5ms
}
engine=0;
while(1)
{

}
}