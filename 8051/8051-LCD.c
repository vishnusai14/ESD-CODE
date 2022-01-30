#include <reg51.h>
#define msec 50
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^6;
unsigned char commands[] = {0x38,0x0E,0x01,0x06,0x81,'\0'};
unsigned char name1[] = {"Welcome To The"};
unsigned char name2[] = {"Embedded World"};
//unsigned char value = 0xf0;
void delay(unsigned int time)
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<1250;j++);
}
void lcdcmd(unsigned char val)
{
P2 = val;
rs = 0;
rw = 0;
en = 1;
delay(1);
en = 0;
}
void display(int val)
{
P2 = val;
rs = 1;
rw = 0;
en = 1;
delay(1);
en = 0;
}
void main()
{
//unsigned char digit[3];
int i,j;
for(i=0;commands[i]!='\0';i++)
{
lcdcmd(commands[i]);
delay(msec);
}
/*digit[0] = (value/0x64)+0x30;
digit[1] = ((value/0x0a)%0x0a)+0x30;
digit[2] = (value%0x0a)+0x30;
for (j=0;j<3;j++)
{
display(digit[j]);
delay(msec)
} */

for(j=0;j<=13;j++)
{
display(name1[j]);
delay(msec);
}
lcdcmd(0xc1);
delay(msec);

for(j=0;j<=13;j++)
{
display(name2[j]);
delay(msec);
}
}