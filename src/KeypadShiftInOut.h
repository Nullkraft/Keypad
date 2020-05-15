#ifndef KEYPAD_SHIFTINOUT_H
#define KEYPAD_SHIFTINOUT_H

//#include "Keypad.h"
#include "KeypadShiftIn.h"
#include "KeypadShiftOut.h"

class KeypadShiftInOut: public KeypadShiftIn, public KeypadShiftOut {
public:
    KeypadShiftInOut(const byte numRows, const byte numCols, uint32_t inDataPin, uint32_t inClockPin, uint32_t inLatchPin, uint32_t outDataPin, uint32_t outClockPin, uint32_t outLatchPin):
//            Keypad(NULL, NULL, numRows, numCols),
            KeypadShiftIn(NULL, numRows, numCols, inDataPin, inClockPin, inLatchPin),
            KeypadShiftOut(NULL, numRows, numCols, outDataPin, outClockPin, outLatchPin)
};

#endif
