#include<avr/io.h>
#include<util/delay.h>
int var = 0;
int angle = 0;
int val = 0;
int main(void)
{
  DDRB = 0xFF;
  LCD lcd;
  lcd.init();
  TCCR0 = 0x03;
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    val = ADCW;
    if(ADCW<100)
    {
      lcd.cmd(0x01);
      lcd.string("GATE OPEN")
      angle = 20
      servo();
    }
    if(checkbit(PIND,bitn(2)))
    {
      lcd.cmd(0x01);
      lcd.string("GATE CLOSE")
      angle = 90
      servo();
    }
  }
}

void servo()
{
  while(!((PIND & 0x04)||(PIND & 0x08)));
  {
    for(int i = 0;i<20;i++)
    {
      int tem = (5 + (angle/10));
      TCNT0 = 0;
      while(var < 200)
      {
        if(TCNT0 == 25)
        {
          var++
          TCNT0 = 0;
        }
        if (var == tem )  
        {
          PORTB = 0x00;
        }
      }
      if ( var == 200)
      {
        PORTB = 0xFF
        var = 0;
      }
    }
  } 
}
