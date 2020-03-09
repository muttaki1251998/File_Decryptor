#include "header.h"

void print_chi_vals(char *string)
{
    double EF[26] = _EF;
    int *text_freq = get_frequency_table(string);
    int n = letter_count(string);
    float chi_sq[26];
    int shift=0, i=0, k=0;
    char c = 'a';    

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
        printf("%d: %f\n", shift, chi_sq[shift]);        
    }
}