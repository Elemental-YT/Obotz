#include<avr/io.h>
#include<util/delay.h> 
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  int val;
  DDRB = 0xFF;
  DDRC = 0xFF;
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    val = ADCW;

    if (val<100)
    {
      PORTB = 0xFF;
      PORTC = 0x00;
    }
    else
    {
      PORTB = 0x00;
      PORTC = 0xFF;
    }
  }
}
