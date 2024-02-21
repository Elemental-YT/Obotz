#include <avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y)) 
#define setbit(x,y) (x1=y)
#define clearbit(x,y) (x&=~y)
#define bitn(p) (0x01 << (p))

int c = 0;
int d =0;
int x,y;
int p =60, q =60,r =60;
int count = 0;
int press = 0;
int count_angle 1, count_angle2.count_angle3;

int main (void)
{

DDRD = 0xFF;
DDRB = 0xFE;
OCRIA = 21;
TCCRIA = 0x00;
TCCR1B = 0x0A;
TIMSK1 = 0x02;
SREG = 0x80;
angle1(60);
angle2(60);
angle3(60);
while(1)
{
    if(checkbit(PINB bitn(PB0))){
        press++;
        _delay_ms(300);
    }
    if(press== 1)
    {
        ADCconversion();
        PORTD = 0x01;
        if(y<100){
            p++;
            angle1(p);

        }
        if(y>800) {
            p--;
            angle(p);
        }
    }  
    if(press==2) { 
        ADCconversion(); 
        PORTD = 0x02; 
        if(y<100){
            q++; 
            angle2(q);
        }  
        if(y>800){
            q--; 
            angle2(q);
        }
    }
    if (press == 3)
    { 
        ADCconversion(); 
        PORTD = 0x04; 
        if(y<100) {
            r++;
            angle3(r);
        } 
        if(y>800) {
            r--;
            angle3(r);
        }
    }
    if (press == 4)
    { 
        ADCconversion(); 
        PORTD = 0x08; 
        if(y<100) {
            c++;
            antistepper();
            _delay_ms(50);
        } 
        if(y>800) {
            d++;
            clkstepper();
            _deply_ms(50);
        }
        if (press == 5)
        { 
            press = 1;
        }
    }

}

void ADCconversion()
{ 
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    x=ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    y=ADCW;
}