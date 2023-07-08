#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int main(void)
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  PORTB = 0xFF;
  PORTC = 0x00;
  while(1)
  {
    for(int j = 0; j <= 4; j++)
    {
      PORTC = 1 << (j);
      for(int i = 0; i <= 4; i++)
      {
        PORTB = ~(1 << (i));
        delay_ms(50);
      }
    }
  }
}