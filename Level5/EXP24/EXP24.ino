#include <LCD.h>
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
  LCD lcd;
  lcd.init();
  lcd.string("Hello");
}
