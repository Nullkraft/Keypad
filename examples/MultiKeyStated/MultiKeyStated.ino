/* @file MultiKey.ino
|| @version 1.2
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
||  08/17/15 - Modified to use the "Stated" Event Listener. - T.B. Trzepacz (SoftEgg)
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
*/

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;


void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    msg = "";
    //calls function "keyEventListener" during any kpd.getKeys() call.
    kpd.addStatedEventListener( keyEventListener );
}

//will be called on change in key state
void keyEventListener(KeypadEvent key, KeyState kpadState) 
{
  //note the change in key state
  switch (kpadState) // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
  {
    case PRESSED:    
      msg = " PRESSED.";
      break;
    case HOLD:
      msg = " HOLD.";
      break;
    case RELEASED:
      msg = " RELEASED.";
      break;
    case IDLE:
      msg = " IDLE.";
      break;
  }
  //show the key and state information on the console.
  Serial.print("Key ");
  Serial.print(key);
  Serial.println(msg);
}

void loop() {
    loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    // But we don't care, because "keyEventListener" takes care of it all now.
    kpd.getKeys();
}  // End loop
