//作者 机电17-1 邴盛楠 2020年5月22日  自动擦鞋机程序
#include "reg52.h"			 

sbit led_power=P0^0;                              //定义电源指示灯led_power为P0引脚
sbit led_run=P0^1;		                          //定义运行灯led_run为P1引脚
sbit engine=P1^0;		                          //定义直流电动机engine为P10引脚
sbit run_button=P3^2;	                          //定义外部中断源为P32引脚
sbit beef=P0^2;			                          //定义蜂鸣器beef为P2引脚
unsigned char second=0;	                          //声明初始化变量second

void Timer0Init()		                          //定时器函数     初始化定时器1（16位定时器）
{
	TMOD|=0X01;
	TH0=0XFC;	
	TL0=0X18;	
	ET0=1;
	EA=1;
	TR0=1;			
}

void delay(int i)		                          //延时函数       用于蜂鸣器
{
    while(i--);
}

void beef_run()			                          //蜂鸣器函数     实现对蜂鸣器的控制
{
    int j;
    for ( j = 0; j < 500; j++)
    {
        beef=~beef;
        delay(100);
    }
}

void Int0Init()				                      //外部中断函数   初始化外部中断
{
    IT0=1;
    EX0=1;
    EA=1; 

}

void run() interrupt 0		                      //外部中断
{
	ET0=1;
    TH0=0XFC;	
	TL0=0X18;
    beef_run();
    Timer0Init();
}

void led_timer() interrupt 1					  //定时器中断
{
	static int i=0;
	engine=1;
	TH0=0XFC;	
	TL0=0X18;
	i++;
	if(i==500)
	{
	    if(second==10)
	    {
		    led_run=0;
			engine=0;
			ET0=0;
			second=0;
            beef_run();
			Int0Init();
	    }
		i=0;
		led_run=~led_run;
		second++;	
	}	
}

void main()										  //主函数
{	
    led_power=0;
	led_run=1;
	engine=0;
    Int0Init();	 
	while(1);		
}