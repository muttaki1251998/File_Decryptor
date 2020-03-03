#include "header.h"

int *frequency_table(char *string)
{
    int _j = 0;
    int *_frequency;
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0 ,q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;

    _frequency = malloc( sizeof(int)*26);
    
    for(_j=0; string[_j] != '\0'; _j++)
    {
        if(string[_j] == 'a' || string[_j] == 'A')
        {
            a++;
        }
        else if(string[_j] == 'b' || string[_j] == 'B')
        {
            b++;
        }
        else if(string[_j] == 'c' || string[_j] == 'C')
        {
            c++;
        }
        else if(string[_j] == 'd' || string[_j] == 'D')
        {
            d++;
        }
        else if(string[_j] == 'e' || string[_j] == 'E')
        {
            e++;
        }
        else if(string[_j] == 'f' || string[_j] == 'F')
        {
            f++;
        }
        else if(string[_j] == 'g' || string[_j] == 'G')
        {
            g++;
        }
        else if(string[_j] == 'h' || string[_j] == 'H')
        {
            h++;
        }
        else if(string[_j] == 'i' || string[_j] == 'I')
        {
            i++;
        }
        else if(string[_j] == 'j' || string[_j] == 'J')
        {
            j++;
        }
        else if(string[_j] == 'k' || string[_j] == 'K')
        {
            k++;
        }
        else if(string[_j] == 'l' || string[_j] == 'L')
        {
            l++;
        }
        else if(string[_j] == 'm' || string[_j] == 'M')
        {
            m++;
        }
        else if(string[_j] == 'n' || string[_j] == 'N')
        {
            n++;
        }
        else if(string[_j] == 'o' || string[_j] == 'O')
        {
            o++;
        }
        else if(string[_j] == 'p' || string[_j] == 'P')
        {
            p++;
        }
        else if(string[_j] == 'q' || string[_j] == 'Q')
        {
            q++;
        }
        else if(string[_j] == 'r' || string[_j] == 'R')
        {
            r++;
        }
        else if(string[_j] == 's' || string[_j] == 'S')
        {
            s++;
        }
        else if(string[_j] == 't' || string[_j] == 'T')
        {
            t++;
        }
        else if(string[_j] == 'u' || string[_j] == 'U')
        {
            u++;
        }
        else if(string[_j] == 'v' || string[_j] == 'V')
        {
            v++;
        }
        else if(string[_j] == 'w' || string[_j] == 'W')
        {
            w++;
        }
        else if(string[_j] == 'x' || string[_j] == 'X')
        {
            x++;
        }
        else if(string[_j] == 'y' || string[_j] == 'Y')
        {
            y++;
        }
        else if(string[_j] == 'z' || string[_j] == 'Z')
        {
            z++;
        }


    }

    _frequency[0] = a;
    _frequency[1] = b;
    _frequency[2] = c;
    _frequency[3] = d;
    _frequency[4] = e;
    _frequency[5] = f;
    _frequency[6] = g;
    _frequency[7] = h;
    _frequency[8] = i;
    _frequency[9] = j;
    _frequency[10] = k;
    _frequency[11] = l;
    _frequency[12] = m;
    _frequency[13] = n;
    _frequency[14] = o;
    _frequency[15] = p;
    _frequency[16] = q;
    _frequency[17] = r;
    _frequency[18] = s;
    _frequency[19] = t;
    _frequency[20] = u;
    _frequency[21] = v;
    _frequency[22] = w;
    _frequency[23] = x;
    _frequency[24] = y;
    _frequency[25] = z;

    
    
    return _frequency;
    
}

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

    printf("\n%d\n", count);

    return count;
    
}

Node *add_input(Node *head, char string)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->input_string = string;
    new_node->next = head;

    return new_node;
        
}

void reverse(Node **head_ref)
{
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next = NULL;

    while(current != NULL)
    {
        next = current->next;

        /* Reverse the current node */
        current->next = prev;

        /* Move pointers on position ahead */
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void free_list(Node *head)
{
    Node *new_head = head;
    Node *old_node = NULL;

    while(new_head != NULL)
    {
        old_node = new_head;
        new_head = new_head->next;
        free(old_node);
    }
}

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

int decode_shift(char *string)
{
    double ef[26] = EF;
    int *text_freq = frequency_table(string);
    int n = letter_count(string);
    int chi_sq;
    int shift=0, j=0;
    char c = 'a';
    int encoded_value = 0;
    int first_temp = 0;
    int is_going = 0;

    for(shift=0; shift<=25; shift++)
    {
        for(j=0; j<=25; j++)
        {   
            encoded_value = (int)encode(c, shift);
            chi_sq = (pow(n * ef[j] - text_freq[encoded_value], 2) / (n * ef[j]));
            c++;            
        }
    }
}

int main(int argc, char *argv[])
{
    Node *head = NULL, *node = NULL;
    int ch, input_sz = 0, file_sz = 0;    
    int i = 0;
    FILE *fp;
    char fc;

    if(argc == 3)
    {
        if(strcmp(argv[1], "-F") != 0)
        {
            fprintf(stderr, "Needs -F argument\n");
            return 0;
        }

        fp = fopen(argv[2], "r");

        if(fp == NULL)
        {
            printf("Cannot open file %s\n", argv[2]);
            exit(1);
        }
        else
        {
            while( (fc=fgetc(fp)) != EOF )
            {
                file_sz++;
                node = add_input(head, fc);
                /* printf("%c\n", node->input_string); */
                head = node;
            }
            char new_string[file_sz];
            reverse(&node);

            head = node;
            while(node != NULL)
            {
                new_string[i] = node->input_string;
                node = node->next;
                i++;
            }
            new_string[i] = '\0';
            /* printf("Contents of the file is \n %s \n", new_string); */

            node = head;
            free_list(node);
            fclose(fp);

            printf("Number of letters in the file is %d\n", letter_count(new_string));
            int *arr = frequency_table(new_string);

            int al=0;
            int alphabet = 65;

            for(al=0; al<=25; al++)
            {           
                printf("%c \t = \t %d\n", alphabet, arr[al]);
                alphabet++;
            }

            if(arr != NULL)
            {
                free(arr);
            }              

        }
   
    }
    else if(argc == 1)
    {
        printf("Please enter a string for encoding\n");

        while( (ch=getc(stdin)) != EOF)
        {
            input_sz++;
            node = add_input(head, ch);
            /* printf("%c\n", node->input_string); */
            head = node; 
        }
        
        char new_string[input_sz];
        reverse(&node);

        head = node;
        while (node != NULL)
        {
            new_string[i] = node->input_string;
            node = node->next;
            i++;
        }
        new_string[i] = '\0'; 
        node = head;
        free_list(node);  

        /* Addons from Q1
        printf("Number of letter is %d\n", letter_count(new_string));
        int *arr = frequency_table(new_string);

        int al=0;
        int alphabet = 65;

        for(al=0; al<=25; al++)
        {           
            printf("%c \t = \t %d\n", alphabet, arr[al]);
            alphabet++;
        }

        if(arr != NULL)
        {
            free(arr);
        }   
        */

        int _e = 0;
        char res[20];

        for(_e=0; new_string[_e] != '\0'; _e++)
        {
            res[_e] = encode(new_string[_e], 2);   
            printf("%c Offset is: %d\n", res[_e], offset(res[_e]));
            
        }
       
    }
    
    
    return 0;
}

