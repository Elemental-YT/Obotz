#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  char var;
  DDRB = 0xFF;
  UCSRA = 0x00;
  UCSRB = 0x18;
  UCSRB = 0x06;
  UBRRH = 0x00;
  UBRRL = 103;

  while(1)
  {
    while(!(checkbit(UCSRA, bitn(RXC))));
    var = UDR;
    if(var == '0')
    {
      PORTB = 0x00;
    }
    if(var == '1')
    {
      PORTB = 0xFF;
    }
  }
}
