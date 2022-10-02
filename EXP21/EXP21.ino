#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  Serial.being (2000000);
  int xval, yval, zval;
    
    while(1)
    {
       ADMUX = 0x45;
       ADCSRA = 0xc7;
       while (checkbit(ADCSRA, bitn(ADsC))));
       xval =ADCW;
       Serial.print("X-axis ");
       Serial.print(xval);
       
       ADMUX = 0x46;
       ADCSRA = 0xc7;
       while(checkbit(ADCSRA, butn(ADSC)));
       yval = ADCW;
       Serial.print(" Y-axis ");
       Serial.print(yval);
       
       ADMUX = 0x47;
       ADCSRA = 0xc7;
       while(checkbit(ADCSRA, bitn(ADSC)));
       zval = ADCW;
       Serial.print(" Z-axis ");
       Serial.println(zval);
       
       _delay_ms(1000);
       
    }
}
