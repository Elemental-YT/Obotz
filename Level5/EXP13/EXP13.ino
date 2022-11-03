#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  DDRD = 0xFB;
  while(1)
  {
    while (!(checkbit (PIND, bitn(2))));
    PORTD = 0x01;
    _delay_ms(500);
    while (!(checkbit (PIND, bitn(2))));
    PORTD = 0x00;
    _delay_ms(500);
  }
}
