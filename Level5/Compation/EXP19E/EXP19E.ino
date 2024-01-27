#include<avr/io.h>
#include<util/delay.h>
#include<LCD.h> 
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  int right;
  int left; 
  LCD lcd;
  lcd.init();
  DDRB = 0xFF;
  DDRC = 0xFF;
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    right = ADCW;

    
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    left = ADCW;
    
    if (right<100)
    {
      PORTB = 0xFF;
      lcd.line1(5);
      lcd.showvalue(right);
      _delay_ms(200);
    }
    else
    {
      PORTB = 0x00;
     
    }

    if (left<100)
    {
      PORTC = 0xFF;
      lcd.line2(5);
      lcd.showvalue(left);
      _delay_ms(200);
    }
    else
    {
      PORTC = 0x00;
     
    }
    lcd.cmd(0x01);
    
    
    
   } 
   
  }
