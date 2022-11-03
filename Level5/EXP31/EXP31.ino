#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  int count;
  double distance;
  Serial.begin(9600);
  DDRB = 0x01;
  int pinstate;
  while(1)
  {
    trigger();
    while(checkbit(PINB, bitn(1)))
    {
      TCCR1A = 0x00;
      TCCR1B = 0x02;
      pinstate = 1;
    }
    while(!checkbit(PINB, bitn(1)) && pinstate ==1)
    {
      TCCR1B = 0x00;
      count = TCNT1;
      distance = (count * 0.008575);
      Serial.println(distance);
      pinstate = 0;
      TCNT1 = 0;
    }
  }
}

void trigger()
{
  PORTB = 0x00;
  _delay_us(10);
  PORTB = 0x01;
  _delay_us(10);
  PORTB = 0x00;
}
