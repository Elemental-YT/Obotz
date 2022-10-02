#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#include <LCD.h>

int main(void)
{
  LCD lcd;
  lcd.int();
  DDRD = 0x00;
  int var = 0;
  while(1)
  {
    if(checkbit(PIND, bitn(2)) && var < 9999)
    {
      var++;
      _delay_ms(300);
      lcd.cmd(0x01);
      lcd.showvalue(var);
    }
    if(checkbit(PIND, bitn(3)) && var >0)
    {
      var--;
      _delay_ms(300);
      lcd.cmd(0x01);
      lcd.showvalue(var);
    }
  }
}
