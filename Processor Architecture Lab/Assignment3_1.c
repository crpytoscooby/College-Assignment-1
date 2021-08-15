/*  Q) Write an Embedded C Program to add two numbers. */

#include <pic18f4550.h>

void main(void)
{
    static int n1, n2, sum;
    n1 = 0x50;      // declaring n1
    n2 = 0x20;      // declaring n2
    sum = n1 + n2;  // adding n1 and n2 and storing in sum variable
    TRISB = 0;      // PORTB will act as an output port
    PORTB = sum;    // sending the sum value to PORTB
    return;
}
