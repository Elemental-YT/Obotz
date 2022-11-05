#include<avr/io.h>
#include<util/delay.h>
#include<LCD.h>
#define Power   0x1FE48B7
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int county;
int on_time = 0;
int off_time = 0;
int bit_position = -2;
long keycode = 0;
int main(void)
{
  IRFun();
}

void greek()
{
  Serial.println("CHIKIN NUGGIT");
}

void IRFun(){
  DDRB = 0xFB;
  Serial.begin(2000000);
  Serial.println("IRFun was succusfully called");
  LCD lcd;
  lcd.init();
  while(1)
  {
    while(!(checkbit(PINB,bitn(2))))
    {
      on_time++;
      if (on_time == 1)
      {
        bit_position++;
        if(bit_pos  ition>= 1 && bit_position<= 32)
        {
          if(off_time > 700 )
          {
            keycode |= (long)1<<(32 - bit_position);
            if ( keycode == Power)
            {
              Serial.println("Power Button was pressed");
              lcd.string("Alram On");
              
            }
          }
        }
        if(bit_position>=32)
        { 
          greek();
          Serial.println(keycode,HEX);
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
