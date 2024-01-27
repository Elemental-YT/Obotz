#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  char data;
  UCSRA = 0x00;
  UCSRB = 0x18;
  UCSRB = 0x06;
  UBRRH = 0x00;
  UBRRL = 103;
  TCCR0 = 0x6B;

  while(1)
  {
    while(!(checkbit(UCSRA, bitn(RXC))));
    data = UDR;
    if(data == '1')
    {
      OCR0 = OCR0 + 20;
    }
    if(data == '0')
    {
      OCR0 = OCR0 - 20;
    }
  }
}
