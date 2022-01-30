#include<reg51.h>
//unsigned char d;
//void main() {

//	while(1)
//	{
//		for(d=0; d<255; d++) 
//		{
//			P1=d;
//		};
//		for(d=255; d>0; d--)
//		{
//			P1=d;
//		}
//	}
		
//}


//void delay(int time) {
//	int i,j;
//	for(i = 0; i < time; i++)
//	for(j = 0; j < 990; j++);
//}

//void main() {
//		while(1) {
//			P1 = 0x00;
//			delay(50);
//			P1 = 0x7f;
//			delay(50);
//			P1 = 0xff;
//			delay(50);
//			P1 = 0x7f;
//		delay(50);
//		}
//}

#include<reg51.h>
 //Port P0 address
void main(){
   int sin_value[12] = {128,192,238,255,238,192,128,64,17,0,17,64};
   int i;
   while(1){
      //infinite loop for LED blinking
      for(i = 0; i<12; i++){
         P1 = sin_value[i];
      }
   }
}