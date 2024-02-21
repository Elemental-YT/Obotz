#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int x, c, d;
int main (void)
{
    DDRD = 0xFF;
    while (1)
    {
        ADMUX = 0x43;
        ADCSRA = 0xC7;
        while (checkbit(ADCSRA, bitn(ADSC)));
        x = ADCW;
        if (x < 100)
        {
            C++;
            antistepper();
            _delay_ms(50);
        }
        else if (x > 800)
        {
            d++;
            clkstepper();
            _delay_ms(50);
        }
        Else
        {
            PORTD = 0x00;
        }
    }
}