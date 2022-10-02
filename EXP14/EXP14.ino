#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main(void)
{
  DDRC = 0xFF;
  DDRD = 0x00;
  while(1)
  {
    if(checkbit(PIND,bitn(2)))
    {
      PORTC = 0b00000010;
      _delay_ms(500);
    }
    if(checkbit(PIND,bitn())
    {
      PORTC = 0b00000001;
      _delay_ms(500);
    }
    PORTC = 0x00;
  }
}
