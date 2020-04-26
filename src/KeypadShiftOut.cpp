#include "KeypadShiftOut.h"

KeypadShiftOut::KeypadShiftOut(const byte *col, const byte numRows, const byte numCols, uint32_t outDataPin, uint32_t outClockPin, uint32_t outLatchPin): Keypad(NULL, col, numRows, numCols) {
    this->outDataPin = outDataPin;
    this->outClockPin = outClockPin;
    this->outLatchPin = outLatchPin;
}

void KeypadShiftOut::initColumnPins() {
    pin_mode(outDataPin, OUTPUT);
    pin_mode(outClockPin, OUTPUT);
    pin_mode(outLatchPin, OUTPUT);
}

void KeypadShiftOut::writeColumnPre(byte n) {
    pin_write(outLatchPin, LOW);
    shiftOut(outDataPin, outClockPin, MSBFIRST, (1 << n));
    pin_write(outLatchPin, HIGH);
}

void KeypadShiftOut::writeColumnPost(byte n) {}
