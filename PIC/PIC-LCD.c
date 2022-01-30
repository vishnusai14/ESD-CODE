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


void lcd_data(unsigned char data) {
    
    PORTD = data;
    RC0 = 1;
    RC1 = 0;
    RC2 = 1;
    __delay_ms(2);
    RC2 = 0;
    
}

void lcd_cmd(unsigned char data) {

    PORTD = data;
    RC0 = 0;
    RC1 = 0;
    RC2 = 1;
    __delay_ms(2);
    RC2 = 0;
    

}


void lcd_string(unsigned char value[], unsigned char num) {

    for(int i = 0 ; i < num ; i++) {
        lcd_data(value[i]);
    }

}

void lcd_init() {
    
    lcd_cmd(0x38);
    lcd_cmd(0x66);
    lcd_cmd(0x0c);
    lcd_cmd(0x01);
    
}

void main() {
    
    TRISD = 0x00;
    TRISC = 0x00;
    lcd_init();
    while(1) {
        lcd_cmd(0x83);
        lcd_string("Vishnu", 6);
        lcd_cmd(0xc3);
        lcd_string("Prasanna", 8);
        
    }
    
    
    
}