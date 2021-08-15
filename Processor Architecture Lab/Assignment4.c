/*  Q) Write an Embedded C Program to interface PIC 18FXXX with LED and blinkint it using specified delay.
        1) Use Timer0 in 16 bit mode.
        2) Assume XTAL = 10 MHz.
        3) Generate a ON and OFF duration of LED as 5ms.
        4) For above delat calculate count value and load it in the program. */

#include <pic18f4550.h>

void myDelay();

void main(void)
{
    TRISD = 0;          // setting PortD as output Port
    while (1)
    {
        PORTD = 0xAA;   // setting PortD value 10101010
        myDelay();      // calling delay for 5ms
        PORTD = 0x55;   // setting PortD value 01010101
        myDelay();      // calling delay for 5ms
    }
    return;
}

// function to generate a delay of 5ms
void myDelay()
{
    T0CON = 0x08;       // Timer0 is acting as a 16 bit timer with no pre-scalar
    TMR0L = 0xFA;       // load lower byte value in TMR0L
    TMR0H = 0xCE;       // load higher byte value in TMR0H

    T0CONbits.TMR0ON = 1;   // timer 0 will be started

    while (INTCONbits.TMR0IF == 0); // checking whether the overflow has occured or not and if occured then stop the Timer
    T0CONbits.TMR0ON = 0;   // stopping the timer
    INTCONbits.TMR0IF = 0;  // resetting the value of TMR0IF
}
