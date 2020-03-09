#include "header.h"

char *decoded_string(char *string, int shift, int file_size)
{
    char *decoded_string  = malloc(sizeof(char) * file_size);
    int i = 0;

    for(i=0; i<strlen(string); i++)
    {
        decoded_string[i] = encode(string[i], shift);
    }

    return decoded_string;
}



