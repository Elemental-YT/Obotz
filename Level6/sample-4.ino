#include<avr/io.h>                  // Header file for AVR chip
#include<avr/interrupt.h>           // Header file for interrupt
int count0=0;                       // Initialize count0 as int data type with value 0
int count2=0;                       // Initialize count2 as int data type with value 0
int main (void)
{ 
    DDRD = 0x0F;                    // Set PD0 to PD3 as output
    SREG = 0x80;                    // Enable global interrupt
    TCCROA = 0x00;                  // Normal part operation
    TCCROB = 0x0B;                  // Prescalar of 64 with CTC mode
    TIMSKO = 0x06;                  // Enable interrupt for OCR0A and OCR0B
    OCROA = 249;                    // Set OCR0A as 249
    OCROB = 249;                    // Set OCR0B as 249
    PORTD = 0x09;                   // Set PD3 and PD1 as high & PD2 and PD0 as low
    while(1)
    { 
    }
}

ISR(TIMERO_COMPA_vect)
{
    count0++;                       // Increment count0 every 1ms
    if(count0 == 250)
    {
        PORTD ^=1<<2;               // Toggle PD2 after 250ms
        PORTD ^=1<<3;               // Toggle PD3 after 250ms
        count0=0;                   // Reset count0
    }
}

ISR(TIMERO_COMPB_vect)
{
    count2++;                       // Increment count2 every 1ms
    if(count2 ==1000)
    {
        PORTD ^=1<<0;               // Toggle PD0 after 1000ms
        PORTD ^=1<<1;               // Toggle PD1 after 1000ms
        count2=0;                   // Reset count2
    }
}