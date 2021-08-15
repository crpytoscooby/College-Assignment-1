/*  Q) Write an Embedded C to multiply 8 bit number by 8 bit number. */

#include <pic18f4550.h>

void main(void)
{
    static int a, b, product, i;
    a = 0x20;   // decimal value = 32   binary = 00100000
    b = 0x07;   // decimal value = 07   binary = 00000111
    product = 0;
    for (i = 0; i < b; i++)
    {
        product = product + a;
    }
    TRISB = 0;
    PORTB = product;
    return;
}

