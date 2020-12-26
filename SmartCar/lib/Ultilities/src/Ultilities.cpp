#include <stdint.h>
#include <arduino.h>
#include "Ultilities.h"

char *Ultilities::doubleToChar(double value)
{
    char *ch = new char[8];
    String str = String(value);
    str.toCharArray(ch, 8);
    return ch;
}