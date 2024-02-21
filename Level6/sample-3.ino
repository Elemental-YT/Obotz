#include<avr/io.h>              //Header file for AVR chip
int main (void)
{ 
    DDRD = 0x01;                // Setting entire PD0 as output
    while(1)
    { 
        PORTD = 0x00;           // Turn off LED
        waitms(500);            // call waitms function to generate delay of 500ms
        PORTD = 0x01;           // Turn on LED
        waitms(20);             // Call waitms
    } 
}

void waitms(int a)
{ 
    int count = 0;              // Initialize variable count
    TCCROA = 0x00;              // Set timer 0 to normal mode
    TCCROB = 0x03;              // Set timer to prescaler of 64
    while(!(count == a))        // Repeat until value of count equals desired value of delay in ms
    {                           
        if ( TCNTO ==249)       // 249 =1 milliseconds
        {   
            count++;            // increase count every 1ms 
            TCNT0=0;            // reset timer 0
        }
    }
}