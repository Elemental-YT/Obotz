#include <LCD.h>

#include<avr/io.h>                                  // Include avr/io.h library
#include<util/delay.h>         
#define checkbit(x,y) ((x) & (y))                   // Create the Checkbit macro 
#define bitn(p) (0x01 << (p))                       // Create the Bitn macro
#define setbit(x,y)(x|=y)                          // Create the Setbit Macro
#define clearbit(x,y) (x&=~y)                       // Create the Clearbit Macro
int count,hours,minutes,seconds;
double distance, distance2; 
int main(void)
{
  Serial.begin(9600);
  DDRB = 0x01;
  DDRD = 0x00;
  DDRC = 0xFF;
  int pinstate;
  TCCR0 = 0x00;
  TCCR0 = 0x02;
  LCD lcd;
  lcd.init();
  while(1)
  {
    trigger();
    while(checkbit(PINB, bitn(1)))
    {
      TCCR1A = 0x00;
      TCCR1B = 0x02;
      pinstate = 1;
    }
    if(checkbit(PIND, bitn(2)))
    {
      distance2 = distance;
    }
    if(TCNT0 = 250)
    {
      seconds++;     
    }
    if(seconds == 60)
    {
      minutes++;
      seconds = 0;
    }
    if(minutes == 60)
    {
      hours++;
      minutes = 0;
    }
    if(hours == 24)
    {
      hours = 0;
    }
    while(!checkbit(PINB, bitn(1)) && pinstate ==1)
    {
      TCCR1B = 0x00;
      count = TCNT1;
      distance = (count * 0.008575);
      Serial.println(distance);
      pinstate = 0;
      TCNT1 = 0;
    }
  }
}

void trigger()
{
  PORTB = 0x00;
  _delay_us(10);
  PORTB = 0x01;
  _delay_us(10);
  PORTB = 0x00;
}


void ET()
{
  if(distance == distance2)
  {
    lcd.string("Car Stolen at");
    lcd.line2();
    lcd.string(hours,minutes,seconds);   
    checkbit(PORTC, bitn(3));
  }
  PORTC = 0x00;
}