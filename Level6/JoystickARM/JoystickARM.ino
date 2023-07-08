#include<avr/io.h>
#include<util/delay.h>
#define clearbit(x,y) (x&= ~y)
#define setbit  (x,y)  (x| = y)
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int c = 0;
int d = 0;
int x,y = 0;
int p = 60, q = 60, r = 60;
int count = 0;
int press = 0;
int count_angle1,count_angle2,count_angle3;
int main (void)
{
  DDRD = 0xFF;
  DDRB = 0xFE;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;  
  TIMISK1 = 0x02;
  SREG = 0x80;
  angle1(60);
  angle2(60);
  angle3(60);
  while(1)
  {
    ADUMX = 0x42;
    ADCSRA = 0xC7;
    while()
  }  
}

                                      