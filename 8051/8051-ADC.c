#include <reg51.h>
#define msec 50

sbit adda = P0^0;
sbit addb = P0^1;
sbit addc = P0^2;
sbit ale = P0^3;
sbit oe = P0^4;
sbit start = P0^5;
sbit eoc = P0^6;
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^6;



unsigned char commands[] = {0x38,0x0E,0x01,0x06,'\0'};
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

void adcinit()
{
	adda = 0;
	addb = 0;
	addc = 0;
	ale = 0;
	oe = 0;
	start = 0;
}

void adcstrtconv()
{
	ale = 1;
	delay(1);
	start = 1;
	delay(5);
	ale = 0;
	start = 0;
	
}

void adcread()
{
	while(eoc !=1);
	oe =1 ;
	
}

void main()
{
	
unsigned char adcdata;
unsigned char digit[3];
int i,j;
adcinit();
addstrtconv();
adcread();
adcdata = P1;
	
for(i=0;commands[i]!='\0';i++)
{
lcdcmd(commands[i]);
delay(msec);
}


digit[0] = (adcdata/0x64)+0x30;
digit[1] = ((adcdata/0x0a)%10)+0x30;
digit[2] = (adcdata%0x0a)+0x30;

for(j = 0; j < 3 ; j++)
{
	display(digit[j]);
	delay(msec);
}
}