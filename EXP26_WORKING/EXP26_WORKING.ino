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
  DDRB = 0xFF;
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
      PORTB = 0x06;
    }
    
    if(wowe >  350)
    {
      lcd.string("BUZZER");
      PORTB = 0x07;
    }
    if(PIND & 0x04 )
    {
      lcd.cmd(0x01);
      PORTB = 0x00;
    }
    }
  }
