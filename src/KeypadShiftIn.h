#ifndef KEYPADSHIFTIN_H
#define KEYPADSHIFTIN_H

#include "Keypad.h"

class KeypadShiftIn: virtual public Keypad {
public:
    KeypadShiftIn(const byte *col, const byte numRows, const byte numCols, uint32_t inDataPin, uint32_t inClockPin, uint32_t inLatchPin);
private:
    uint32_t inDataPin;
    uint32_t inClockPin;
    uint32_t inLatchPin;
    uint32_t inBuffer = 0;

    void initRowPins();
    bool readRow(byte n);
};


#endif
