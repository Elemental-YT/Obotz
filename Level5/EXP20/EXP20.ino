#include<avr/io.h>
#include<util/delay.h> 
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  int right;
  int left;
  DDRB = 0xFF;
  DDRC = 0xFF;
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    _delay_ms(10);
    right = ADCW;

    
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    _delay_ms(10);
    left = ADCW;
    
    if (right<100)
    {
      PORTB = 0xFF;
      
    }
    else
    {
      PORTB = 0x00;
     
    }

    if (left<100)
    {
      PORTC = 0xFF;
      
    }
    else
    {
      PORTC = 0x00;
     
    }
  }
  }
