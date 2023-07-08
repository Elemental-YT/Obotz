#include<avr/io.h>                              
#include<util/delay.h>                      
#define setbit(x,y)(x|=y)
#define clearbit(x,y)(x&=~y)
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b0110001, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011}
int main (void)
{
  DDRC = 0xFF
  while(1)
  {
    for (int i=0;i<10;i++) 
    {
      PORTC = number[i]
      _delay_ms(500)
    }
  }  
}