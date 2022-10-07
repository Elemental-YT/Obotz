*+#include<avr/io.h>*
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
#define key5 0x01FEB04F
long keycode = 0;
int main(void)
{
  DDRB = 0xFB;
  int on_time = 0;
  int off_time = 0;
  int bitposition
  while(1)
  {
    while(!(checkbit(PINB,bitn(2))))
    {
      on_time++;
      if (on_time == 1)
      {
        bit_position++;
        if(bit_poition>= 1 && bit_positionon<= 32)
        {
          if(off_time > 700 )
          {
            keycode |= (long)1<<(32 - bit_position);
          }
        }
        if(bit_position>=32)
        {
          Compare();
          bit_position = -2
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
    off_time = 0
    bit_position = -2
   }
}

void Compare()
{
  if (keycode == key5)
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
