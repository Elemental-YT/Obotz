#include<avr/io.h>                              
#include<util/delay.h>                      
#define setbit(x,y)(x|=y)
#define clearbit(x,y)(x&=~y)
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int i=0;
long result, average;
int main (void)
{
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ASSC)));
    result = result+ADCW;
    i++;

        
    if(i>99)
    {
      average = result/100;
      Serial.println(avarage)
      result = 0;
      i = 0;
    }   
  }
}