//
// Created by dzervas on 4/26/20.
//

#ifndef KEYPAD_SHIFTOUT_H
#define KEYPAD_SHIFTOUT_H

#include "Keypad.h"

class KeypadShiftOut: virtual public Keypad {
public:
    KeypadShiftOut(const byte *row, const byte numRows, const byte numCols, uint32_t outDataPin, uint32_t outClockPin, uint32_t outLatchPin);
private:
    uint32_t outDataPin;
    uint32_t outClockPin;
    uint32_t outLatchPin;

    void initColumnPins();
    void writeColumnPre(byte n);
};


#endif
