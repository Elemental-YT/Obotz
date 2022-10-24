#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#include <LCD.h>
int wewo;
int wowe;
int main(void)
{
  LCD lcd;
  lcd.init();
  DDRD = 0xFB;
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    Serial.println(ADCW);
    wewo = ADCW;
    _delay_ms(500);
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    Serial.println(ADCW);
    wowe = ADCW;
    
    if(wewo > 350)
    {
      
      lcd.string("LED");
      PORTD = 0b00000100;
    }
    
    if(wowe >  350)
    {
      lcd.string("BUZZER");
      PORTD = 0b00001000;
    }
    if(PIND & 0x04 )
    {
      lcd.cmd(0x01);
      PORTD = 0x00;
    }
    }
  }
