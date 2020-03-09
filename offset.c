#include "header.h"

int offset(char letter)
{
    int _offset;

    if(letter >= 'a' && letter <= 'z')
    {
        _offset = letter - 'a'; 
    }
    else if(letter >= 'A' && letter <= 'Z')
    {
        _offset = letter - 'A';
    }

    return _offset;
}