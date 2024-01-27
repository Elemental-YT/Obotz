#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  char data;
  DDRB = 0xFF;
  UCSRA = 0x00;
  UCSRB = 0x18;
  UCSRB = 0x06;
  UBRRH = 0x00;
  UBRRL = 103;

  while(1)
  {
    while(!(checkbit(UCSRA, bitn(RXC))));
    data = UDR;
    if(data == '0')
    {
      PORTD = 0b00100000;
    }
    if(data == '1')
    {
      PORTD = 0b00010000;
    }
    if(data == '2')
    {
      PORTD = 0b11110000;
    }
  }
}
