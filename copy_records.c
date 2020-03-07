#include "header.h"

int main(int argc, char *arhv[])
{
    unsigned int num = 5648;
    int int_vals[12];
    int i=0;

    /* Create 12 integer values */
    for(i=0; i<=12; i++)
    {
        int_vals[i] = i;
    }

    FILE *fp;
    fp = fopen("testme", "wb");
    fwrite(&num, sizeof(num), 1, fp);
    
    fclose(fp);
}