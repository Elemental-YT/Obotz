*+#include<avr/io.h>*
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int var = 0;
int angle = 0;
char vr;
int main(void)
{
  DDRB = 0xFB;
  Serial.begin(2000000);
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
          Serial.println(keycode,HEX);
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
