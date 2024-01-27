#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  int xval;
  DDRD = 0xFF;
  DDRB = 0xFF;

  while(1)
  {
    ADMUX = 0x45;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    xval = ADCW;
    if(xval > 370)
    {
      PORTD = 0xFF;
      PORTB = 0x00;
    }
    if(xval < 320)
    {
      PORTD = 0x00;
      PORTB = 0xFF;
    }
  }
}
