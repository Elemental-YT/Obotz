#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x|= y)
#define clearbit(x,y) (x&= ~y)
#define bitn(p) (0x01 << (p))
int count,angle,count_angle,
int main (void)
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1b = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  HP();
  _delay_ms(2000)
  while(1)
  {
    for(angle = 90; angle <= 130; angle++)
    {    
      convert_n();
    }
    for(angle = 130; angle <= 90; angle--)
    {    
      convert_s();
    }
  }
}


void convert_n()
{
    count_angle = angle + 46;
    delay_us(3000);
}

void convert_s()
{
    count_angle = angle + 46;
    delay_us(35000);
}

void HP()
{
  angle = 90
}

ISR(TIMER1_COMPA_vect)
{
  count++;
  if(count <= count_angle) 
  {
    setbit(PORTD, bitn(4));
  } 

  if ((count > count_angle) && (count < 1818)) {
    clearbit(PORTD, bitn(4));
  }  

  if(count > 1818)
  {
  count = 0
  }
}