#include<avr/io.h>
#include<util/delay.h>
int var = 0;
int main (void)
{
  Serial.begin(2000000);
  while(1)
  {
    Serial.println(var);
    var++;
    _delay_ms(100);
  }
}
