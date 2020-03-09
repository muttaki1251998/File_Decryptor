#include "header.h"

void print_frequency_table(int *table)
{
    int alphabet  = 65;
    int i = 0;

    for(i=0; i<=25; i++)
    {
        printf("%c \t = \t %d\n", alphabet, table[i]);
        alphabet++;
    }

}