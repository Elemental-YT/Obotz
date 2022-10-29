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
  Serial.begin(20000000);
  while(1)
  {
    while(!(checkbit(UCSRA, bitn(RXC))));
    var = UDR;
    if(var == 'a')
    {
      PORTB = 0x00;
      Serial.println("OFF");
    }
    if(var == 's')
    {
      PORTB = 0xFF;
      Serial.println("On");
    }
  }
}
