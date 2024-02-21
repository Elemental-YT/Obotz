#include<avr/io.h>
#include<util/delay.h>
#define checkbit(xy) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main(void)
{
    int x;
    int y:
    Serial.begin(2000000);
    while(1)
    {
        ADMUX=0x42;
        ADCSRA = 0xC7:
        while((ADCSRA& (1<<ADSC)));
        y=ADCW:
        ADMUX=0x43;
        ADCSRA = 0xC7;
        while((ADCSRA& (1<<ADSC))):
        x=ADCW:
        Serial.print("X-axis: ");
        Serial.print(x):
        Serial.print(" Y-axis: ");
        Serial.printin(y):
    }
}