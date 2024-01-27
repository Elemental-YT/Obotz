#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int var = 0;
int angle = 0;
char vr;
int main(void)
{
  DDRB = 0xFF;
  UCSRA = 0x00;
  UCSRB = 0x18;
  UCSRC = 0x06;
  UBRRH = 0x00;
  UBRRL = 0x67;
  while(1)
  {
    while(!(checkbit(UCSRA,bitn(RXC))));
    vr = UDR;
    if(var == '1')
    {
      angle = 20;
      servo();
    }
    else
    {
      angle = 90;
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
