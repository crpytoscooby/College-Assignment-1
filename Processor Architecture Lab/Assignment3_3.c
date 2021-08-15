/*  Q) Write an Embedded C Program to transfer element from one location to another memory location (Internal to Internal). */

// Swapping two array's
#include <pic18f4550.h>

void main(void)
{
    int source_Array[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
    int destination_Array[5] = {0x66, 0x77, 0x88, 0x99, 0xAA};
    static int i, temp;
    for (i = 0; i < 5; i++)
    {
        temp = source_Array[i];
        source_Array[i] = destination_Array[i];
        destination_Array[i] = temp;
    }
    return;
}

/*
// Coping contents from one array to another array
#include <pic18f4550.h>

void main(void)
{
    int source_Array[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
    int destination_Array[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
    static int i;
    TRISB = 0;
    for (i = 0; i < 5; i++)
    {
        destination_Array[i] = source_Array[i];
        PORTB = destination_Array[i];
    }
    return;
} */
