#include<avr/io.h>
#include<util/delay.h>
int main (void)
{
  DDRC = 0b11111111;
  Serial.begin(2000000);
  int var = 0b11110000;
  int var1 = 0b00000000;
  PORTC = 0b10101010;
  while(1)
  {
    int result1 = var || PORTC;
    Serial.println(result1,BIN);
    _delay_ms(5000);

    int result2 = var && PORTC;
    Serial.println(result2,BIN);
    _delay_ms(5000);

    int result3 = var1 && PORTC;
    Serial.println(result3,BIN);
    _delay_ms(5000);

    int result4 = !(PORTC);
    Serial.println(result4,BIN);
    _delay_ms(5000);

    int result5 = !(var1);
    Serial.println(result4,BIN);
    _delay_ms(5000);
  }
}
