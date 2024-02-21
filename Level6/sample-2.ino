#include<avr/io.h>                      // Header file for AVR chip
#include<util/delay.h>                  // Header fiel for delay
int offcount = 0;                       // Initialize variable offcount as int data type 
int oncount = 0;                        // Initialize variable oncount as int data type
int main (void)
{ 
    DDRD = 0x01;                        // Setting entire PD0 as output
    TCCR2A = 0x00;                      // Timer 2 normal mode
    TCCROA = 0x00;                      // Timer 0 normal mode
    TCCROB = 0x03;                      // Prescaler of 64 for timer 0

    while(1)
    {

        if(TCNTO ==249)                 // 249 =1 millisenconds
        {
            offcount++;                 // incrememnt offcount every 1ms
            TCNTO = 0;                  // reset timer 0
        }

        if (offcount == 1000)           
        {

            PORTD = 0x01;               // Turn on LED
            offcount = 0;               // Reset the value of offcount
            TCCROB = 0;                 // Turn off timer 0
            TCCR2B = 0x03;              // Turn on timer 2

        } 
        if (TCNT2 == 249)               // 249 = 1 millisonds
        {
            oncount++;                  // Increment oncount every 1ms
            TCNT2 = 0;                  // Reset timer 2
        }

        if( oncount ==100)
        {
            PORTD = 0x00;               // Turn off LED
            oncount = 0;                // Reset the value of oncount
            TCCR2B = 0;                 // Turn off timer 2
            TCCROB = 0x03;              // Turn on timer 0
        }

    }

}