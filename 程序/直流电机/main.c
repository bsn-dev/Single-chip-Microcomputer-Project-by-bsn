#include <reg52.h>
#include <intrins.h>

sbit engine=P1^0;

//????delay
void delay(int i)
{
    while(i--);
}

//???
void main()
{
long i;
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