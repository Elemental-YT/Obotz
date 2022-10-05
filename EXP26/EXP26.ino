#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#include <LCD.h>

int main(void)
{
  LCD lcd;
  lcd.init();
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    Serial.println(ADCW);
    lcd.cmd(0x01);
    lcd.showvalue(ADCW);
    _delay_ms(500);

  }
}
