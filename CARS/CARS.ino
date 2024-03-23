#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main(void)
{
  DDRB = 0xEF;
  DDRD = 0xFF;
  TCCR0 = 0x6B;
  OCR0 = 0;
  Serial.begin(2000000);
  while(1)
  {
  if((checkbit(PINB,bitn(4))))
  { 
    Serial.println("PB4 High");
    PORTD = 0xFF;
    OCR0 = 255;
  }
  else 
  {
    PORTD = 0x00;
    OCR0 = 0;
  }
}
}

