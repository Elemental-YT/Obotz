#include<avr/io.h>
#include<util/delay.h> 
#include<avr/interrupt.h>
#define setbit(x,y) ( x |=y)
#define clearbit(x,y) (x&=~y) #define bitn(p) (0x01 << (p) )
int count = 0;
int count_angle= 0;
int main(void)
{ 
    DDRB = OxFF:
    OCR1A = 21
    TCCRIA = 0x00; 
    TCCR1B = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;
    while (1)
    {
        angle(0);
        _delay_ms(500); 
        angle (30);
        _delay_ms(500);
        angle (60); 
        _delay_ms(500);
        angle (90);
        _delay_ms(500);
        angle (120);
        _delay_ms(500);
        angle (180);
        _delay_ms(500);
    }
}

void angle(int a)
{
    count_angle= a +46; 
}

ISR (TIMER1_COMPA_vect) 
{
    count++;
    if (count <= count_angle) 
    {
        setbit (PORTB,bitn(4));
    } 
    else if ((count > count_ang) && (count <1818))
    { 
        clearbit (PORTB,bitn(4));
    } 
    else if (count >= 1818)
    {
        count = 0;
    }
}