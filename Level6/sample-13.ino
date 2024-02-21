#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define key1 0x1CE8271F
#define key2 0xCE1234F
#define key3 0x1CE12bnF
long keycode=0;
int timervalue;
int bitposition = 0;
int var = 0;
int main (void)
{
    DDRB = 0x00;
    DDRD = 0xFF;
    TIMISK0 = 0x01;
    EICRA = 0x20;
    EIMSK = 0x04;
    SREG = 0x80;
    TCCR0A = 0x00;
    TCCR0B = 0x03;
}

void compare()
{
    if (keycode == key1)
    {
        PORTD = 0x04;
    }

    if (keycode == key2)
    {
        PORTD = 0x04;
    }

    if (keycode == key3)
    {
        PORTD = 0x0C;
    }
}

ISR (TIMER0_OVF_vect)
{
    var++
    TCNT0 = 125;
}

ISR(INT2_vect)
{
    timervalue = var; 
    var = 0;
    bitposition++;
    if(timervalue> = 100 )
    {
        bitposition = -2;
        keycode = 0;
    }
    if((bitposition>=0) && (bitposition<32)) 
    {
        if(timervalue>3)
        { 
            keycode |=(long) 1<<(31-bitposition);
        }
        else if(bitposition>=32)
        {
            bitposition = 0
            compare()
        }
    }

} 