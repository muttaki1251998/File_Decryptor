#include "header.h"

char encode(char letter, int shift)
{
   
    int i = 0;
    int temp, upper_case, lower_case;
    lower_case = letter - 'a';
    upper_case = letter - 'A';
    char res;
    int new_shift = 0;    

    if(lower_case >= MIN && lower_case < MAX)
    {
        if(shift > 0)
        {
            temp = ((lower_case + shift) % 26) + 97;
        }
        else if(shift < 0)
        {
            new_shift = shift + 26;
            temp = ((lower_case + new_shift) % 26) + 97;
        }
        res = (char)temp;
    }
    else if(upper_case >= MIN && upper_case < MAX)
    {   
       if(shift > 0 )
       {
           temp = ((upper_case + shift) % 26) + 65;
       }
       else if(shift < 0)
       {
           new_shift = shift + 26;
           temp = ((upper_case + new_shift) % 26) + 65;
       }
       res = (char)temp;
    }
    else
    {
        res = letter;
    }    

    return res;
    
}