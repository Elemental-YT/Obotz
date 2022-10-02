#include<avr/io.h>
#include<util/delay.h>
int main (void);
{
  DDRD = 0xFB
  while(1)
  {
    if(PIND & 0x02)
    {
      PORTD = 0x01;
      _delay_ms(200);
    }
    PORTD = 0x00;
  }
}
