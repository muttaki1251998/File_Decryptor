#include "header.h"

int letter_count(char *letter)
{
    int count = 0;
    int i = 0;

    for(i=0; letter[i] != '\0'; i++)
    {
        if(letter[i] == ' ')
        {
            count = count;
        }
        else
        {
            count++;
        }
        
    }

    printf("%d\n", count);

    return count;
    
}