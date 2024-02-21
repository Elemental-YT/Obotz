#include <avr/io.h> 
#include<util/delay.h> 
int main(void)
{ 
    int period = 500; 
    DDRD = OxFO; 
    while (1)
    { 
        for(int i = 0; i < 12; i++)
        {

        PORTD = 0b1110000;
        _deldy_ms(period) ; 
        
        PORTD =0b11010000 ;
        _delay_ms(period); 
        
        PORTD =0b1011000 ; 
        _delay_ms(period);

        PORTD =0b01110000;
        _delay_ms(period);

        } 
        
        for(int i=0;i<12;i++)
        { 
            PORTD =0b01110000;
            _delay_ms(period); 
            
            PORTD =0b10110000;
            _delay_ms(period); 
            
            PORTD = 0b11010000;
            _delay_ms(period);

            PORTD = 0b11100000; 
            _delay_ms(period);

        }
    }
}