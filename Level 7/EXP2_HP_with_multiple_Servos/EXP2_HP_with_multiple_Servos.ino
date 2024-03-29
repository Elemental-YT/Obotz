#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x|= y)
#define clearbit(x,y) (x&= ~y)
#define bitn(p) (0x01 << (p))
int count,angle,angle1, count_angle,count_angle1;
int main (void)
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  HP();
  _delay_ms(2000);
  while(1)
  {
    for(int i = 1; i<= 30; i++)
    {
      angle++;
      angle1++;    
      convert();
    }    
    _delay_ms(1000);
    for(int i = 1; i<= 30; i++)
    {
      angle--;
      angle1--;    
      convert();
    }    
    _delay_ms(1000);
    
  }
}

  
void convert()
{
    count_angle = angle + 46;
    count_angle1 = angle1 + 46;
}

void HP()
{
  angle = 90;
  angle1 = 90;
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
  count = 0;
  }
  
  if(count <= count_angle1) 
  {
    setbit(PORTD, bitn(5));
  } 

  if ((count > count_angle1) && (count < 1818)) {
    clearbit(PORTD, bitn(5));
  }  
}