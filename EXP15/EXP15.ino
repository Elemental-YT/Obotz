#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  DDRB = 0xFF;
  DDRD = 0x00;
  while(1)
  {
    if((checkbit (PIND,bitn(2)))&&
    (checkbit (PIND,bitn(3)))
    {
      PORTB = 0xFF;
      _delay_ms(500);
    }
    PORTB = 0x00;
  }
}
