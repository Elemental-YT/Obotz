#include<avr/io.h> 
#include<util/delay.h>
int count0,count1;
int count2,count3;
int main(void)
{ 
    DDRD = OxFF;
    SREG = 0x80;
    TCCROA = 0x00
    TCCROB = 0x0B; 
    PiMSKO = 0x06;
    OCROA = 249;
    OCROB=249;
    TCCR * 2A = 0x00;
    TCCR2B = 0x0B;
    TIMSK2 = 0x06;
    OCR2A = 249;
    OCR2B = 249;
    while(1)
    {
    }
}

ISR (TIMERO_COMPA_vect) 
{
    count0++; 
    if(count0 == 100)   
    { 
        PORTD ^=1<<0; 
        count0=0;
    }
}

ISR(TIMERO_COMPB_vect) 
{

    count1++;
    if (count1 == 200) 
    {
        PORTD =1<<1; 
        count1=0;
    }

} 
ISR(TIMER2_COMPA_vect) 
{

    count2++; 
    if(count2 == 300)
    { 
        PORTD ^=1<<2; 
        count2=0;
    }
}

ISR(TIMER2_COMPB_vect)
{
    count3++;
    if(count3 ==50)
    {
        PORTD ^=1<<3;
        count3=0;
    }
}