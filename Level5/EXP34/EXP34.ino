#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#include <LCD.h>
int main(void)
{
  int count;
  LCD lcd;
  lcd.init();
  DDRC = 0xFF
  DDRB = 0x01;
  double distance;
  int pinstate;
  while(1)
  {
    trigger();
    while(checkbit(PINB, bitn(1)))
    {
      TCCR1A = 0x00;
      TCCR1B = 0x02;
      pinstate = 1;
    }
    while(!checkbit(PINB, bitn(1)) && pinstate ==1)
    {
      TCCR1B = 0x00;
      count = TCNT1;
      distance = (count * 0.008575);
      lcd.cmd(0x01);
      lcd.cmd(0x0C);
      lcd.showvalue(distance);
      _delay_ms(500);
      pinstate = 0;
      TCNT1 = 0;
    }
  }
}

void trigger()
{
  PORTB = 0x00;
  _delay_us(10);
  PORTB = 0x01;
  _delay_us(10);
  PORTB = 0x00; 
}

void compare()
{
  if (distance < 10) 
  {
    OCR0 = (distance*10)
  }
  else

}
