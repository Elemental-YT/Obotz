#include<avr/io.h> 
#include<util/delay.h> 
#include<avr/interrupt.h>
#define key1 0x1CE8271F
#define key2 0xCE1234F
#define key3 0x1CE12bnF
#define key4 0x1CE8271F
#define key5 0xCE1234F
#define key6 0x1CE12bnF
#define key7 0x1CE8271F
#define key8 0xCE1234F
#define setbit(x,y) ( x |=y)
#define clearbit(x,y) (x * 8 = - y) 
#define bitn(p) (0x01 << (p) )
int c = 0
int d =0;
int count = 0
int count_angle3, count_angle1,count_angle2;
long keycode=0;
int timervalue;
int bitposition = 0;
int var = 0;
int main (void)
{
    DDRB = 0x00;
    DDRD = 0xFF;
    TIMISK0 = 0x01;
    EICRA = 0x20;
    EIMSK = 0x04;
    SREG = 0x80;
    TCCR0A = 0x00;
    TCCR0B = 0x03;
}
   
}
void antistepper()
{ 
    if (c ==1)
    {
        PORTD = 0b11100000;
    }
    if (c == 2)
    {
        PORTD =0b1101000
    }
    if (c == 3)
    {
        PORTD = 0b10110000;
    } 
    if (c == 4) 
    { 
        PORTD = 0b01110000; 
        c = 0;
    }

} 

void clkstepper()
{ 
    if (d ==1)
    { 
        PORTD = 0b01110000;
    } 
    if (d ==2)
    { 
        PORTD = 0b10110000;
    }
    if (d ==3)
    { 
        PORTD = 0b11010000;
    } 
    if( d ==4)
    { 
        PORTD = 0b11100000; 
        d = 0;
    }
}

void angle 1 (int a)
{
    count_angle1 l = a + 4t ;

} 
void angle2(int b)
{

    count_angle2 = b +46;

} 
void angle3(int c)
{ 
    count_angle3 = c +46;

}
void compare()
{
    if (keycode == key1)
    {
        PORTD = 0x04;
    }

    if (keycode == key2)
    {
        PORTD = 0x04;
    }

    if (keycode == key3)
    {
        PORTD = 0x0C;
    }
}

ISR (TIMER0_OVF_vect)
{
    var++
    TCNT0 = 125;
}

ISR(INT2_vect)
{
    timervalue = var; 
    var = 0;
    bitposition++;
    if(timervalue> = 100 )
    {
        bitposition = -2;
        keycode = 0;
    }
    if((bitposition>=0) && (bitposition<32)) 
    {
        if(timervalue>3)
        { 
            keycode |=(long) 1<<(31-bitposition);
        }
        else if(bitposition>=32)
        {
            bitposition = 0
            compare()
        }
    }

} 
ISR (TIMER1_COMPA_vect)
{
    count++;
    if (count <= count_angle1)
    {
        setbit (PORTB, bitn(5)); 
    }
    else if ((count > count_angle 1) && (count < 1818))
    {
        clearbit(PORTB, bitn(5)); 
    }
    else if (count >= 1818)
    {
        count = 0;
    } 
    if (count <= count_angle2)
    { 
        setbit (PORTB, bitn(6));
    } 
    else if ((count > count_angle2) && (count < 1818))
    { 
        clearbit(PORTB, bitn(6));

    } 
    else if (count >= 1818)
    {
        count = 0;
    }
    if (count <= count_angle3)
    { 
        setbit (PORTB, bitn(7));
    }
    else if ((count > count_angle3) && (count < 1818
    { 
        clearbit(PORTB, bitn(7));
    } 
    else if (count >= 1818)
    {
        count = 0;
    } 
}