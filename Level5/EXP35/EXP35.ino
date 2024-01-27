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
    angle = 0;
    servo();
    _delay_ms(500);
    angle = 60;
    servo();
    _delay_ms(500);
    angle = 120;
    servo();
    _delay_ms(500);
    angle = 180;
    servo();
    _delay_ms(500);
  }
}

void servo()
{
  for(int i = 0;i<20;i++)
  {
    int tem = (5 + (angle/10));
    TCNT0 = 0;
    while(var < 200)
    {
      if(TCNT0 == 25)
      {
        var++;
        TCNT0 = 0;
      }
      if (var == tem )
      {
        PORTB = 0x00;
      }
    }
    if ( var == 200)
    {
      PORTB = 0xFF;
      var = 0;
    }
  }
}
