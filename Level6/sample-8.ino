#include<avr/io.h> 
#include<util/delay.h> 
int main(void)
{ 
    int period = 50; 
    DDRD = 0xFO; 
    int count = 0; 
    int angle = 90; 
    int pulses=0; 
    while (1)
    {
        pulses = angle/7.5; 
        while(count < pulses)
        {
            PORTD = 0b11100000; 
            _delay_ms(period); 
            count++;

            PORTD = 0b11010000; 
            _delay_ms(period);
            count++;

            PORTD = 0b10110000; 
            _delay_ms(period);
            count++;

            PORTD = 0b01110000; 
            _delay_ms(period);
            count++;
        }
    }

}