#include<avr/io.h> 
#include<util/delay.h> 
#include<avr/interrupt.h>
#define setbit(x,y) ( x |=y)
#define clearbit(x,y) (x * 8 = - y) 
#define bitn(p) (0x01 << (p) )
int c = 0
int d =0;
int count = 0
int count_angle3, count_angle1,count_angle2;
int main (void)
{
    DDRD = 0xFF;
    DDRB = 0xFF;
    OCR1A = 21;
    TCCR1A = 0x00;
    TCCRIB = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;
    while(1)
    {
        angle1(60);
        angle2(60);
        angle3(60);
        _delay_ms(500)
        angle3(10);_
        delay_ms(500);
        for (int i = 0 i<12; i++)
        {
            C++;
            antistepper(); 
            _delay_ms(50):
        }
        _deplay_ms(500);
        angle3(60);
        _delay_ms(500);
        for (int i = 0 i < 12 i++) 
        {
            d++; 
            clkstepper();
            _delay_ms(50);
        }
        _delay_ms(500);
    }
}