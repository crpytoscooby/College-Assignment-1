/*  Q) Write an Embedded C Program to add array of n numbers. */

#include <pic18f4550.h>

void main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    static int i, sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum = sum + array[i];
    }
    TRISB = 0;
    PORTB = sum;
    return;
}
