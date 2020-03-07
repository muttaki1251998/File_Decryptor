#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#define MIN 0
#define MAX 26
#define _EF {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.0236, 0.0015, 0.01974, 0.00074}
#define OFF 0
#define ON 1

typedef struct Lists
{
    char input_string;
    struct Lists *next;
} Node;

typedef struct BinFile
{
    char two_four[24];
    double d_value[24];
    char one_four[144];
    int one_two[12];
} Records;


