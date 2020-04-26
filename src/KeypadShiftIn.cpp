#include "KeypadShiftIn.h"

// Custom implementation of shiftIn that fixes the clock bug (original taken from arduino core wiring_shift.c)
// A clock was done in the wrong way (first high then low) and the reading was done between the clocking
uint32_t shiftIn(uint32_t ulDataPin, uint32_t ulClockPin, uint32_t ulBitOrder) {
    uint8_t value = 0;
    uint8_t i;

    for (i=0; i < 8; ++i) {
        if ( ulBitOrder == LSBFIRST )
            value |= digitalRead(ulDataPin) << i;
        else
            value |= digitalRead(ulDataPin) << (7 - i);

        digitalWrite(ulClockPin, LOW);
        digitalWrite(ulClockPin, HIGH);
    }

    return value;
}

KeypadShiftIn::KeypadShiftIn(const byte *col, const byte numRows, const byte numCols, uint32_t inDataPin, uint32_t inClockPin, uint32_t inLatchPin): Keypad(NULL, col, numRows, numCols) {
    this->inDataPin = inDataPin;
    this->inClockPin = inClockPin;
    this->inLatchPin = inLatchPin;

    pin_write(inLatchPin, LOW);
    pin_write(inClockPin, HIGH);
}

void KeypadShiftIn::initRowPins() {
    pin_mode(inDataPin, INPUT);
    pin_mode(inClockPin, OUTPUT);
    pin_mode(inLatchPin, OUTPUT);

    pin_write(inLatchPin, LOW);
    pin_write(inClockPin, HIGH);
}

bool KeypadShiftIn::readRow(byte n) {
    if (n % 8 == 0) {
        pin_write(inLatchPin, HIGH);
        delayMicroseconds(1);
        pin_write(inLatchPin, LOW);

        inBuffer = shiftIn(inDataPin, inClockPin, MSBFIRST);
    }

    return (inBuffer & (1 << n)) == 0;
}