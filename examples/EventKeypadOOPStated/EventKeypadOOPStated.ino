/* @file EventKeypadStated.pde
 || @version 1.1
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || 08/17/2015 - Modified to use "Stated" Event Listener - T.B. Trzepacz (SoftEgg)
 || 
 || @description
 || | Demonstrates using the KeypadEvent.
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

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = LED_BUILTIN; 

boolean blink = false;
boolean ledPin_state;

class Menu {
public:
    char menuPosition = NULL;

    static void updateMenu(void *context, KeypadEvent key, KeyState kpadState) {
        if (kpadState == PRESSED) {
            reinterpret_cast<Menu *>(context)->setMenuPosition(key);
        }

        void setMenuPosition(char key) {
            menuPosition = key
        }
    };
}


Menu menu;

void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.

    keypad.addOOPEventListener(Menu::updateMenu, menu); // Add an event listener for this keypad
}

void loop(){
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}


