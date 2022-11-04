#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#define Power  0x1FE48B7
#define Mute   0x1FE7887
#include <LCD.h>
int on_time = 0;                              // Variable for on_time
int off_time = 0;                             // Variable for off_time
int bit_position = -2;                        // Variable for bit_position
long keycode = 0;                             // Variable for keycode
int LED;                                    // Variable for LED
int BUZZ;                                   // Variable for Buzzer
int power;                                  // Variable for power
int main(void)
{
  DDRD = 0xFF;                                // Int Output as port D
  DDRB = 0xFF;
  Serial.begin(2000000);                      // Initialize serial communication at baud rate of 2000000 bps
  while (1)                                   // Start the Forever Loop
  {
  
    ADMUX = 0x40;                             // Set A0 As the ADC conversion pin
    ADCSRA = 0xC7;                            // Start the ADC conversion
    while (checkbit(ADCSRA, bitn(ADSC)));     // Wait until the ADC conversion is done
    Serial.println(ADCW);                     // Print the output onto the Serial Moniter
    LED = ADCW;                               // Save the output into the Variable LED
    _delay_ms(500);                           // Wait for 500 miliseconds
    ADMUX = 0x41;                             // Set A1 As the ADC conversion pin
    ADCSRA = 0xC7;                            // Start the ADC conversion
    while (checkbit(ADCSRA, bitn(ADSC)));     // Wait until the ADC conversion is done
    Serial.println(ADCW);                     // Print the output onto the Serial Moniter
    BUZZ = ADCW;                              // Save the output into the Variable BUZZ
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
  if(keycode == Power)
    {
      power++;
      _delay_ms(570);
      Serial.println("Power");
    }
    if (power == 1)
    {
    if (LED > 350)                            // If LED is greater than 350
    {
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b00100000;                     // Set PD5 as High and everything else Low
    }

    if (BUZZ >  350)                          // If BUZZ is greater than 350
    {
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b01000000;                     // Set PD6 as High and everything else Low
    }

    if ((LED > 350) && (BUZZ > 350))          // If LED & BUZZ are greater than 350
    {
      PORTD = 0b00000000;                     // Turn Everything off
    }
  }
  if(power == 2)
  {
    lcd.string("OFF");
  }
  if (keycode == Mute)                         // If Button 1 is Pressed
  {
    lcd.cmd(0x01);                          // Clear LCD screen
    _delay_ms(570);
  }
}
}
