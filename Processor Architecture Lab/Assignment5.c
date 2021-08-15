/* 	Q) Write an Embedded C program for Timer programming ISR based buzzer on/off. */

#include <pic18f4550.h>

void main(void)
{
	TRISD = 0X00;
	PORTDbits.RD0 = 0x01;
	timer0_start();
	while (1)
	{
		TRISB = 0x00;
		TRISC = 0xff;
		PORTC = PORTB;
	}
}

void interrupt()
{
	TMR0L = 0x00;
	TMR0H = 0x00;
	INTCONbits.TMR0IF = 0;
}

void timer0_start()
{
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 1;
	INTCONbits.TMR0IE = 1;
	INTCONbits.TMR0IF = 0;
	PORTDbits.RD0 = 0x00;
	T0CON = 0x08;
	TMR0L = 0x00;
	TMR0H = 0x00;
	T0CONbits.TMR0ON = 1;
}