#include <reg52.h>
#include <intrins.h>

sbit led_power=P0^0;
sbit led_run=P0^1;
sbit engine=P1^0;

//��ʱ����delay
void delay(int i)
{
    while(i--);
}

//������
void main()
{
long i;
led_power=0;
engine=0;

for(i=0;i<50;i++) //ѭ��400��,��Լ18s
{
    engine=1;
	led_run=0;
    delay(5000);  //һ��Լ5ms
}
engine=0;
led_run=1;

while(1)
{
   
}
}