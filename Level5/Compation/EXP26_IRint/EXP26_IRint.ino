#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#define Power  0x1FE48B7
#define Mode   0x1FE58A7
#include <LCD.h>
int on_time = 0;                              // Variable for on_time
int off_time = 0;                             // Variable for off_time
int bit_position = -2;                        // Variable for bit_position
long keycode = 0;                             // Variable for keycode
int led;                                    // Variable for LED
int BUZZ;                                   // Variable for Buzzer
int power;                                  // Variable for power
int main(void)
{
 
  DDRB = 0xFB;
  Serial.begin(2000000);
  int on_time = 0;
  int off_time = 0;
  int bit_position = -2;
  long keycode = 0;
  while(1)
  {
    while(!(checkbit(PINB,bitn(2))))
    {
      on_time++;
      if (on_time == 1)
      {
        bit_position++;
        if(bit_position>= 1 && bit_position<= 32)
        {
          if(off_time > 700 )
          {
            keycode |= (long)1<<(32 - bit_position);
          }
        }
        if(bit_position>=32)
        {
          Ir();
          Serial.println(keycode,HEX);
          Serial.println(power);
          bit_position = -2;
          keycode = 0;
        }
      }
    
    off_time = 0;   
    }
  while((checkbit(PINB,bitn(2))))
  {
   off_time++;
   on_time = 0;
   if (off_time > 6000)
   {
    off_time = 0;
    bit_position = -2;
   }
}
}
}

void Ir()
{
  LCD lcd;                                    // Creating an object class named LCD
  lcd.init();                                 // Initializing the LCD
  if(keycode == Mode)
    {
      power = power + 1;
      _delay_ms(570);
    }
    if (power == 1)
    {
    if (led > 350)                            // If LED is greater than 350
    {
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b00100000;                     // Set PD5 as High and everything else Low
    }

    if (BUZZ >  350)                          // If BUZZ is greater than 350
    {
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b01000000;                     // Set PD6 as High and everything else Low
    }

    if ((led > 350) && (BUZZ > 350))          // If LED & BUZZ are greater than 350
    {
      PORTD = 0b00000000;                     // Turn Everything off
    }
  }
  if(power == 2)
  {
    lcd.string("OFF");
  }
  if (keycode == Power)                         // If Button 1 is Pressed
  {
    lcd.cmd(0x01);                          // Clear LCD screen
    _delay_ms(570);
  }
}
