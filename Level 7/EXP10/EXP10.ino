#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x|= y)
#define clearbit(x,y) (x&= ~y)
#define bitn(p) (0x01 << (p))
int count = 0;
int right_hip,right_foot,right_hand,left_hip,left_foot,left_hand,count_angle,count_angle1,count_angle2,count_angle3,count_angle4,count_angle5;
int main(void)
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1b = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  HP();
  CT();
  while(1)
  {
    for(right_foot = 90; right_foot >= 80; right_foot--)
    {
      CT();
    }
    for(right_foot = 80; right_foot >= 90; right_foot++)
    {
      CT();
    }
  }
}



