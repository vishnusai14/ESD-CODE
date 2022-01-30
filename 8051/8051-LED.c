#include <reg51.h>


void delay() {
	int i, j;
	for(i = 0; i < 100; i++)
	for(j = 0 ; j < 1250; j++);
}

void main() {
	int i, j;
	unsigned int digit[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
	while(1){
		for(i = 0 ; i < 9 ; i++) {
			P2 = digit[i];
			delay();
		};
		for(j = 9 ; j >= 0 ; j--){
			P2 = digit[j];
			delay();
		};
	}
}
