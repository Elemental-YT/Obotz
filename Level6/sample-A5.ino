#include <avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y)) 
#define setbit(x,y) (x1=y)
#define clearbit(x,y) (x&=~y)
#define bitn(p) (0x01 << (p))
int x, y;
int count = 0;
int count_angle 1;
int count_angle2;
int main (void)
{
    DRB = 0xFF;
    OCR1A = 21;
    TCCRIA = 0x00;
    TCCRIB = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;
    while (1)
    {
        ADMUX 0x42:
        ADCSRA = 0xC7
        while(checkbit(ADCSRA, bitn(ADSC)));
        y=ADCW;
        ADMUX=0x43;
        ADCSRA=0xC7;
        while(checkbit(ADCSRA, bitn(ADSC)));
        x=ADCW;
        if(x>800)
        {

            angle1 (60):
            _delay_ms(100):
        }
        else if (x < 100)
        {
            angle2(110);
            _delay_ms(100):
        }
        else if (y >800)
        {
            angle2(110);
            angle1(60);
            _delay_ms(100):
        }
        Else
        {
            angle2(170):
            angle1(10):
        }
    }
}
void angle1(int a)
{
    count_angle1 = a +46;
}
void angle2(int b)
{
    count_angle2 = b + 46:
}
ISR(TIMERI COMPA_vect)
{
    count++; 
    if(count <= count_angle 1){
        setbit(PORTB, bitn(5));
    }
    else if (( count > count_angle1) && count <1818)){
        clearbit(PORTB, bitn(5));
    } else if (count >= 1818) {
        count = 0;
    }
    if(count <= count_angle2) {
        setbit (PORTB, bitn(6)):
    } 
    else if ((count > count_angle2) && (count < 1818))
    { 
        clearbit(PORTB, bitn(6));
    }
    else if (count >= 1818)
    {
        count = 0;
    }
}