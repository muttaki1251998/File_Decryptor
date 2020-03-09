#include "header.h"

int letter_count(char *letter)
{
    int count = 0;
    int i = 0;

    for(i=0; letter[i] != '\0'; i++)
    {
        if( (letter[i] > 96 && letter[i] < 123) || (letter[i] > 64 && letter[i] < 91))
        {
            count++;
        }
        else
        {
           count = count;
        }
        
    }

    return count;
    
}