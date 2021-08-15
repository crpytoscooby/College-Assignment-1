/*  Q) Write an Embedded C Program for sorting the numbers in ascending and descending order. */

#include <pic18f4550.h>

void main(void)
{
    // array contents: 50 63 3 44 119
    int array[5] = {0x32, 0x3F, 0x03, 0x2C, 0x77};
    static int i, j, temp;

    // sorting the numbers in ascending order
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5 - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // sorting the numbers in descending order
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5 - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return;
}
