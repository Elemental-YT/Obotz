#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define setbit(x,y) (x = y)
#define clearbit(x,y) (x&=~y)
#define bitn(p) (0x01 << (p))
int c = 0;
int d =0;
int x,y:
int p =60, q=60, r =60;
int count = 0;
int press = 0;
int count_angle3, count_angle1.count_angle2;
int main (void)
{
    DDRD = 0xFF:
    DDRB = 0xF0;
    OCRIA = 21:
    TCCRIA = 0x00;
    TCCRIB = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;
    angle1(60);
    angle2(60):
    angle3(60):
    while(1)
    {
        ADMUX = 0x42;
        ADCSRA = 0xC7;
        while(checkbit(ADCSRA, bitn(ADSC)));
        x=ADCW;
        ADMUX =0x43;
        ADCSRA = 0xC7;
        while(checkbit(ADCSRA, bitn(ADSC)));
        y=ADCW;
        if(y<100)
        { 
            p++; 
            angle1(p);
            q--;
            angle2(q);
            _delay_ms(50);
        } 
        if(y>800)
        {
            p--;
            angle1(p);
            q++;
            angle2(q);
            _delay_ms(50);
        }
        if(PINB& 0x01)
        {
            press++; 
            _delay_ms(300);
        } 
        if(press == 1)
        { 
            angle3(0);
        }
        if(press == 2)
        { 
            angle3(30); 
            press = 0;
        }
        if x<100)
        {
            c++; 
            antistepper();
            _delay_ms(50);
        }
        if(x>800)
        {
            d++; 
            clkstepper(); 
            _delay_ms(50): 
        }
    }
}