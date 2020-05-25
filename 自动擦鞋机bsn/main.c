//���� ����17-1 ��ʢ� 2020��5��22��  �Զ���Ь������
#include "reg52.h"			 

sbit led_power=P0^0;                              //�����Դָʾ��led_powerΪP0����
sbit led_run=P0^1;		                          //�������е�led_runΪP1����
sbit engine=P1^0;		                          //����ֱ���綯��engineΪP10����
sbit run_button=P3^2;	                          //�����ⲿ�ж�ԴΪP32����
sbit beef=P0^2;			                          //���������beefΪP2����
unsigned char second=0;	                          //������ʼ������second

void Timer0Init()		                          //��ʱ������     ��ʼ����ʱ��1��16λ��ʱ����
{
	TMOD|=0X01;
	TH0=0XFC;	
	TL0=0X18;	
	ET0=1;
	EA=1;
	TR0=1;			
}

void delay(int i)		                          //��ʱ����       ���ڷ�����
{
    while(i--);
}

void beef_run()			                          //����������     ʵ�ֶԷ������Ŀ���
{
    int j;
    for ( j = 0; j < 500; j++)
    {
        beef=~beef;
        delay(100);
    }
}

void Int0Init()				                      //�ⲿ�жϺ���   ��ʼ���ⲿ�ж�
{
    IT0=1;
    EX0=1;
    EA=1; 

}

void run() interrupt 0		                      //�ⲿ�ж�
{
	ET0=1;
    TH0=0XFC;	
	TL0=0X18;
    beef_run();
    Timer0Init();
}

void led_timer() interrupt 1					  //��ʱ���ж�
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

void main()										  //������
{	
    led_power=0;
	led_run=1;
	engine=0;
    Int0Init();	 
	while(1);		
}