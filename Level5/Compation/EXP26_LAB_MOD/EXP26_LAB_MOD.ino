#include<avr/io.h>
#include<util/delay.h>
#include <LCD.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#define Power  0x1FE48B7                      // Initialize Power
#define Mute   0x1FE7887                      // Initialize Mute 

int on_time = 0;                              // Initialize On Time and set it to 0
int off_time = 0;                             // Initialize off time and set it to 0
int bit_position = -2;                        // Initialize Bit position and set it to -2
long keycode = 0;                             // Initialize keycode as a LONG veriable

int main(void)
{
  IRremote();                                 // Go To IRremote Void Funciton
}

void IRsensor()
{
  int LED;                                    // Variable for LED 
  int BUZZ;                                   // Variable for Buzzer
  int power;                                  // Variable for power
  LCD lcd;                                    // Creating an object of class LCD (Liquid Crystal Display)
  lcd.init();                                 // Initialize the LCD (Liquid Crystal Display)          
  DDRD = 0xFF;                                // Int Output as port D
  DDRB = 0xFF;      
  Serial.begin(2000000);                      // Initialize serial communication at baud rate of 2000000 bps
    ADMUX = 0x40;                             // Set A0 As the ADC conversion pin
    ADCSRA = 0xC7;                            // Start the ADC conversion
    while(checkbit(ADCSRA, bitn(ADSC)));      // Wait until the ADC conversion is done
    Serial.println(ADCW);                     // Print the output onto the Serial Moniter
    LED = ADCW;                               // Save the output into the Variable LED
    _delay_ms(500);                           // Wait for 500 miliseconds
    ADMUX = 0x41;                             // Set A1 As the ADC conversion pin
    ADCSRA = 0xC7;                            // Start the ADC conversion
    while(checkbit(ADCSRA, bitn(ADSC)));      // Wait until the ADC conversion is done
    Serial.println(ADCW);                     // Print the output onto the Serial Moniter
    BUZZ = ADCW;                              // Save the output into the Variable BUZZ
    if((BUZZ <  350) && (LED >  350))         // If LED is greater than 350 and Buzz is lower Than 350
    {
      lcd.cmd(0x01);                          // Clear The LCD (Liquid Crystal Display)
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b00100000;                     // Set Port D Pin 5 as High and everything else Low
    }
    
    if((BUZZ >  350) && (LED <  350))         // If BUZZ is greater than 350 and LED is low than 350
    {
      lcd.cmd(0x01);                          // Clear The LCD 
      lcd.string("Alert! ");                  // Print on the LCD  "Alert!"
      PORTD = 0b01000000;                     // Set Port D Pin 6 as High and everything else Low
    }
    
    if((LED > 350) && (BUZZ > 350))           // If LED & BUZZ are greater than 350 
    {
      PORTD = 0b00000000;                     // Turn Set All Pins On PORT D To Low
      lcd.cmd(0x01);                          // Clear The LCD 
      lcd.string("Alarm On");                 // Print on the  " Alarm On "
    }
    }
}


void IRremote(){
  DDRB = 0xFB;                                                            // Set Port B Pin 2 As Input For The TSOP ( Thin Small Outlined Package )
  Serial.begin(2000000);                                                  // Set The Serial Moniters Baud Rate to 2000000 bps
  LCD lcd;                                                                // Create a Object Called LCD (Liquid Crystal Display)
  lcd.init();                                                             // Initialize The LCD (Liquid Crystal Display)
  while(1)                                                                // Start The Forever Loop
  {
    while(!(checkbit(PINB,bitn(2))))                                      // If TSOP recived a Signal
    {
      on_time++;                                                          // Increase On Time By One 
      if (on_time == 1)                                                   // If On Time Equals to One 
      {
        bit_position++;                                                   // Increase Bit Position by One
        if(bit_position>= 1 && bit_position<= 32)                         // If Bit Position Is Greater or equals to one AND Is Less Than Or Equals to 32
        {
          if(off_time > 700 )                                             // If Off Time Is Greater Than 700     
          {
            keycode |= (long)1<<(32 - bit_position);                      // Copy The Values Just Recived From the TSOP ( Thin Small Outlined Package )
            if ( keycode == Power)                                        // If Power Is Pressed
            {               
              lcd.string("Alarm On");                                     // Print On the LCD (Liquid Crystal Display) " Alarm On "
              _delay_ms(600);                                             // Delay The code for 600 milloseconds 
              IRsensor();                                                 // Go to THe IRsensor Void Function
            }
          }
        }
        if(bit_position>=32)                                              // If Bitposition is Greater or Equals to 32
        { 
          
          Serial.println(keycode,HEX);                                    // Convert keycode into HEX then print the value onto the Serial Moniter
          bit_position = -2;                                              // Set The Bit Position to -2
          keycode = 0;                                                    // Delete The Saved Keycode
        }
      }
    
    off_time = 0;                                                         // Off Time Equals to 0
    }
  while((checkbit(PINB,bitn(2))))                                         // If the TSOP Recived Nothing
  {
   off_time++;                                                            // Increase the off time by 1
   on_time = 0;                                                           // Set the on tie to 0
   if (off_time > 6000)                                                   // If the Off Time Is Greater than 6000
   {
    off_time = 0;                                                         // Set the Off Time to 0
    bit_position = -2;                                                    // Set The Bit position to -2
   }
  }
 } 
}
