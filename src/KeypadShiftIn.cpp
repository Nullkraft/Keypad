//
// Created by dzervas on 4/26/20.
//

#include "KeypadShiftIn.h"

KeypadShiftIn::KeypadShiftIn(const byte *col, const byte numRows, const byte numCols, uint32_t inDataPin, uint32_t inClockPin, uint32_t inLatchPin): Keypad(NULL, col, numRows, numCols) {
    this->inDataPin = inDataPin;
    this->inClockPin = inClockPin;
    this->inLatchPin = inLatchPin;
}

void KeypadShiftIn::initRowPins() {
    pin_mode(inDataPin, INPUT);
    pin_mode(inClockPin, OUTPUT);
    pin_mode(inLatchPin, OUTPUT);

    pin_write(inLatchPin, LOW);
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