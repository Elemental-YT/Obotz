#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#include <LCD.h>

int main(void)
{
  LCD lcd;
  lcd.init();
  lcd.string("Hello");
}
