#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
#define B5 0x1FEB04F
long keycode = 0;
int count = 0;
int main(void)
{
  DDRB = 0xFB;
  int on_time = 0;
  int off_time = 0;
  int bit_position;
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
          compare();
          Serial.println(keycode,HEX);
          bit_position = -2;
          keycode = 0;
        }
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
void compare()
{
  if (keycode == B5)
  {
    count++;
    _delay_ms(500);
  }
  if(count == 1)
  {
    PORTC = 0xFF;
    PORTD = 0x00;
  }
  if(count == 2)
  {
    PORTC = 0x00;
    PORTD = 0x01;
    count = 0;
  }
}
