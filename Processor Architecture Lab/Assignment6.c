/* 	Q) Write an Embedded C program for LCD interfacing with PIC 18FXXX. */

#include <pic18f4550.h>

#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

void LCDCMD(unsigned char x);
void LCDDATA(unsigned char x);
void delay(unsigned int time);

void main()
{
	ADCON1 = 0x0F;
	TRISE = 0x00;
	TRISD = 0x00;
	LCDCMD(0x01);	// clear screen command
	LCDCMD(0x80); 	// force cursor to beginning from 1st line
	LCDCMD(0x38);	// 2nd line and 5*7 matrix
	LCDCMD(0x0E);	// display on, cursor blinking
	LCDCMD(0x06);	// increment cursor (shift cursor to right)

	LCDDATA('W');
	LCDDATA('E');
	LCDDATA('L');
	LCDDATA('C');
	LCDDATA('O');
	LCDDATA('M');
	LCDDATA('E');

	LCDCMD(0xC0);	// force cursor to beginning of 2nd line
	LCDDATA('P');
	LCDDATA('V');
	LCDDATA('G');
	LCDDATA('C');
	LCDDATA('O');
	LCDDATA('E');
	LCDDATA('T');
	while (1);
}

void LCDCMD(unsigned char x)
{
	PORTD = x;	// send command to PORTD
	rs = 0; 	// select command register
	rw = 0; 	// read the data
	en = 1; 	// high to low transition
	delay(100);
	en = 0;
	delay(100);
}

void LCDDATA(unsigned char x)
{
	PORTD = x;	// sending data to PORTD
	rs = 1;		// select data register
	rw = 0;		// write
	en = 1;		// high to low transition
	delay(100);
	en = 0;
	delay(100);
}

void delay(unsigned int time)
{
	int i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 750; j++);
}
