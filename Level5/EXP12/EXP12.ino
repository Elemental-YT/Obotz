#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  DDRB = 0xFF;
  DDRD = 0x00;
  int count = 0;
  while(1)
  {
    if(checkbit(PIND, bitn(2)))
    {
      count++;
      _delay_ms(500);
    }
    if ( count == 1 )
    {
      PORTB = 0xFF ;
    }
    if ( count == 2 )
    {
      PORTB = 0x00 ;
    }
    if ( count == 3 )
    {
      count = 1 ;
    }
  }
}
