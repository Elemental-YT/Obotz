#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
#define B1 0x1FE50AF
#define B2 0x1FED827
int on_time = 0;
int off_time = 0;
int bit_position = -2;
long keycode = 0;
int main(void)
{
  DDRD = 0xFF;
  DDRB = 0xFB;
  TCCR1B = 0x6B;
  OCR0 = 0;
  Serial.begin(2000000);
  while(1)
  {
    
    while(!(checkbit(PINB,bitn(2))))
    {
      on_time++;
      if (on_time == 1)
      {
        bit_position++;
        if(bit_position>= 1 && bit_position<= 32)
        {
          if(off_time > 700 )
          {
            keycode |= (long)1<<(32 - bit_position);
          }
        }
        if(bit_position>=32)
        {
          Serial.println(keycode,HEX);
          CP();
          bit_position = -2;
          keycode = 0;
        }
      }
    
    off_time = 0;   
    }
  while((checkbit(PINB,bitn(2))))
  {
   off_time++;
   on_time = 0;
   if (off_time > 6000)
   {
    off_time = 0;
    bit_position = -2;
   }
}
}
}

void CP()
{
  Serial.println(" Entered CP ");
  if (keycode == B1)
  {
    Serial.println(" Entered B1 ");
    PORTD = 0xFF;
    OCR0 = 255;
  }

  if( keycode == B2 )
  {
    Serial.println(" Entered B2 ");
    PORTD = 0x00;
    OCR0 = 0;
  }
}

