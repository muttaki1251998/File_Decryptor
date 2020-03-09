#include "header.h"

int encode_shift(char *string)
{
    double EF[26] = _EF;
    int *text_freq = get_frequency_table(string);
    int n = letter_count(string);
    float chi_sq[26];
    int shift=0, i=0, j=0, k;
    char c = 'a';
    float smallest_chi, smallest_chi_shift;
    int encoded_value;

    for(i=0; i<25; i++)
    {
        chi_sq[i] = 0.0;
    }
    
    for(shift=0; shift<=25; shift++)
    {
        for(k=0; k<=25; k++)
        {   
            chi_sq[shift] += pow( (n * EF[offset(c)] - text_freq[offset(encode(c, shift))]), 2) /   (n * n * EF[offset(c)]);       
            c++;      
        }
        c = 'a';       
    }

    smallest_chi = chi_sq[0];
    for(i=1; i<=25; i++)
    {
        if(smallest_chi > chi_sq[i])
        {
            smallest_chi = chi_sq[i];
            smallest_chi_shift = i;
        }         
    }

    if(smallest_chi <= 0.5)
    {
        encoded_value = smallest_chi_shift;
    }
    else
    {
        encoded_value = 0;
    }

    return encoded_value;

}