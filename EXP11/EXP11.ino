#include<avr/io.h>
#include<util/delay.h>
int main (void);
{
  DDRD = 0b11111011;
  while(1)
  {
    if(checkbit(PIND, bitn(1)))
    {
      PORTD = 0b00000001;
      _delay_ms(200);
    }
    else
    {
    PORTD = 0b00000010;
    }
  }
}
