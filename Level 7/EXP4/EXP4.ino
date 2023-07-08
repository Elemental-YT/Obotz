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
    PORTC = 0x01;
    PORTB = 0b11111110;
    _delay_ms(1000);
    PORTC = 0b00000010;
    _delay_ms(1000);
    PORTC = 0b00000100;
    _delay_ms(1000);
    PORTC = 0b00001000;
    _delay_ms(1000);
    PORTC = 0b00010000;
    _delay_ms(1000);
  }
}