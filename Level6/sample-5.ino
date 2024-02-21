#include <avr/io.h>             // Header file for AVR chip
#include<util/delay.h>          // Header file for delay
int count0, count1;             // Initialise variables
int main (void)
{   
    DDRD = 0xFF;                // Set port D as output
    SREG = 0x80;                // Enable global interrupt
    TCCROA = 0x00;              // Normal port operation
    TCCROB = 0x03;              // Prescaler of 64
    TMSKO = 0x01;               // Enable interrupt for overlflow
    TCNTO = 200;                // Set TCNT0 to  200
    TCNT2 = 100;                // Set TCNT2 to 100
    TCCR2A = 0x00;              // Normal port operation
    TCCR2B = 0x03;              // Presclar of 64
    TIMSK2 = 0x01;              // Enable interrupt for overflow
    while (1)
    { 
    }
}

ISR(TIMERO_OVF_vect)            // ISR for timer 0 over flow
{
    count0++;                   // Increment count 0 everytime  timer 0 overflows
    if(count0 == 2000)          // Check if timer has overflown 2000 times
    { 
        PORTD ^= 1 <<0;         // toggle pin PD0
        count0 = 0;             // set count0 to 0
    } 
    TCNTO = 200;                // reinitialize TCNT0 to 200
} 
ISR(TIMER2_OVF_vect)            // ISR for timer 2 overflow
{
    count1++;                   // Increment count 1 every time timer 0 overflow
    if (count1 ==2000)          // check if timer has overflow 2000 times
    { 
        PORTD ^= 1 <<1;         // toggle pin PD1
        count1 = 0;             // set count1 to 0
    } 
    TCNT2 = 100;                // reinitilize TCNT0 to 100

}