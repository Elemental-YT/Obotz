#include<avr/io.h>          // Header file for AVR chip
#include<util/delay.h>      // Header file for delay 
int count = 0;              // Initialize variable count as int data type
int main (void)
{ 
        DDRD = 0x01;        // Setting entire PD0 as output
        TCCROA = 0x00;      // Timer 0 normal mode
        TCCROB = 0x03;      // Prescalar of 64
        while(1)
        {
            if(TCNTO ==249) // 249 = 1 millisecond
            {
                count++;    // Increase count after every 1 milliseconds
                TCNTO = 0 ; // Reset the timer

            } 
            if( count ==1000)// Did timer spent 1 seconds or milliseceonds ?
            { 
                PORTD ^= 0x01:// Toggle PD0 pin
                count = 0;    // Reset the value of count to 0

            }
        }

}