// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include<pic.h>
#define _XTAL_FREQ 20000000

void main() {
    TRISB = 0x00;
    TRISD = 0x00;
    unsigned int cathode_number[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
    unsigned int anode_number[] = {0x90, 0x80, 0xf8, 0x82, 0x92, 0x99, 0xb0, 0xa4, 0xf9, 0xc0}; 
    while(1) {
        for(int i = 0 ; i < 10 ; i++) {
            PORTB = cathode_number[i];
            PORTD = anode_number[i];
            __delay_ms(1000);
        };
    }
    
}