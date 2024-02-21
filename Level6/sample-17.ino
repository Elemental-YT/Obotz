#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int x,z;
int count = 0;
int count_angle;
int main (void)
{
    DDRB = 0xFF;
    OCR1A = 21;
    TCCRIA = 0x00;
    TCCR1B = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;
    while (1)
    {
        ADMUX = 0x42;
        ADCSRA = 0xC7;
        while (checkbit(ADCSRA, bitn(ADSC)));
        x = ADCW;
        z = x* 0.175;
        angle(z);
    }
}
