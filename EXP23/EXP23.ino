#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  TCCR0 = 0x6B;
  DDRB = 0xFF;
  DDRD = 0x00;
  OCR0 = 0;
  Serial.begin(2000000);
  while(1)
  {

      OCR0 = 1;
      _delay_ms(200);
      Serial.println(OCR0);
      OCR0 = 50;
      _delay_ms(200);
      Serial.println(OCR0);
    
  }
}
