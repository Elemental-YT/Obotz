#include<avr/io.h>
#include<util/delay.h>
int var = 0;
int angle = 0;
int main(void)
{
  DDRB = 0xFF;
  TCCR0 = 0x03;
  while(1)
  {
    if(checkbit(PIND,bitn(2)))
    {
      _delay_ms(300);
      angle = angle + 10
    }
    if(checkbit(PIND,bitn(2)))
    {
      _delay_ms(300);
      angle = angle - 10
    }
  }
}

void servo()
{
  while(!((PIND & 0x04)||(PIND & 0x08)));
  {
    for(int i = 0;i<20;i++)
    {
      int tem = (5 + (angle/10));
      TCNT0 = 0;
      while(var < 200)
      {
        if(TCNT0 == 25)
        {
          var++
          TCNT0 = 0;
        }
        if (var == tem )  
        {
          PORTB = 0x00;
        }
      }
      if ( var == 200)
      {
        PORTB = 0xFF
        var = 0;
      }
    }
  } 
}
