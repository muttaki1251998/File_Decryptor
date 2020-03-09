#include "header.h"

int to_decode(int shift)
{
    int decode_shift = 26 - shift;

    return decode_shift;
}
