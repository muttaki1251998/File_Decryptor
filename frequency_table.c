#include "header.h"


int main(int argc, char *argv[])
{
    Node *head = NULL, *node = NULL;
    int ch, input_sz = 0, file_sz = 0, _character_count = 0;    
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

            _character_count = character_count(new_string);

            printf("Number of letters are %d\n", letter_count(new_string));
            printf("Number of characters: %d\n", _character_count);
            int *arr = get_frequency_table(new_string);

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

        _character_count = character_count(new_string);

        printf("Number of letters are %d\n", letter_count(new_string));
        printf("Number of characters: %d\n", _character_count);

        int *arr = get_frequency_table(new_string);

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
   
    return 0;
}

int character_count(char *string)
{
    int count = 0;
    int i = 0;

    for(i=0; string[i] != '\0'; i++)
    {
        if( (string[i] > 96 && string[i] < 123) || (string[i] > 64 && string[i] < 91) || (string[i] >= 33 && string[i] <= 47))
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
