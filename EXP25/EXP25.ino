#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#include <LCD.h>

int main(void)
{
  LCD lcd;
  lcd.int();

  while(1)
  {
    for(int i =0; i<16; i+)
    {
      lcd.cmd(0x01);
      lcd.line1(i);
      lcd.string("Hello");
      lcd.line2(3);
      lcd.string("World");

      _delay_ms(500);
    }
  }
}
