#include "KeypadShiftIn.h"

// Custom implementation of shiftIn that fixes the clock bug (original taken from arduino core wiring_shift.c)
// A clock was done in the wrong way (first high then low) and the reading was done between the clocking
uint32_t shiftIn(uint32_t ulDataPin, uint32_t ulClockPin, uint32_t ulBitOrder) {
    uint8_t value = 0;
    uint8_t i;

    for (i=0; i < 8; ++i) {
        digitalWrite(ulClockPin, LOW);
        delayMicroseconds(2);

        if (ulBitOrder == LSBFIRST)
            value |= digitalRead(ulDataPin) << i;
        else
            value |= digitalRead(ulDataPin) << (7 - i);

        digitalWrite(ulClockPin, HIGH);
    }

    return value;
}

KeypadShiftIn::KeypadShiftIn(const byte *row, const byte numRows, const byte numCols, uint32_t inDataPin, uint32_t inClockPin, uint32_t inLatchPin): Keypad(row, NULL, numRows, numCols) {
    this->inDataPin = inDataPin;
    this->inClockPin = inClockPin;
    this->inLatchPin = inLatchPin;

    pin_write(inLatchPin, LOW);
    pin_write(inClockPin, HIGH);
}

void KeypadShiftIn::initColumnPins() {
    pin_mode(inDataPin, INPUT);
    pin_mode(inClockPin, OUTPUT);
    pin_mode(inLatchPin, OUTPUT);

    pin_write(inLatchPin, LOW);
    pin_write(inClockPin, HIGH);
}

bool KeypadShiftIn::readRow(byte n) {
    if (n == 0) {
        pin_write(inLatchPin, HIGH);
        delayMicroseconds(20);
        pin_write(inLatchPin, LOW);
    }

    // Handle daisy-chained shift registers
    if (n % 8 == 0) {
        uint32_t tmp = shiftIn(inDataPin, inClockPin, MSBFIRST);
        this->inBuffer = tmp;
    }

    return (this->inBuffer & (1 << (n % 8))) == 0;
}