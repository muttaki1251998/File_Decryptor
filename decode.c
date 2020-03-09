#include "header.h"

int main(int argc, char *argv[])
{
    Node *head = NULL, *node = NULL;
    int ch, input_sz = 0, file_sz = 0;  
    int i = 0, j = 0;
    FILE *fp, *output_fp;
    char fc;
    int decoded_value, letters = 0;
    char *main_string;
    int *freq_table;
    if(argc > 10)
    {
        printf("Too many arguements\n");
    }

    char *input_file = NULL;
    char *output_file = NULL;
    int flag_F = OFF, flag_O = OFF, flag_S = OFF, flag_s = OFF, flag_n = OFF, flag_x = OFF, flag_t = OFF;

    for(i=1; i<argc; i++) 
    {
        if(argv[i][0] == '-')
        {
            j = 0;

            while(argv[i][j] != '\0')
            {
                if(argv[i][j] == 'F' && flag_F == OFF)
                {
                    flag_F = ON;
                    /* printf("-F present\n"); */
                    input_file = malloc(sizeof(char) * strlen(argv[i+1]));
                    /* printf("File name size: %ld\n", strlen(argv[i+1])); */
                    strcpy(input_file, argv[i+1]);
                    /* printf("Input file name: %s\n", input_file); */
                }
                if(argv[i][j] == 'O' && flag_O == OFF)
                {
                    flag_O = ON;
                    /* printf("-O present\n"); */
                    output_file = malloc(sizeof(char) * strlen(argv[i+1]));
                    /* printf("File name size: %ld\n", strlen(argv[i+1])); */
                    strcpy(output_file, argv[i+1]);
                    /* printf("Output file name: %s\n", output_file); */
                }
                if(argv[i][j] == 'n' && flag_n == OFF)
                {
                    flag_n = ON;
                }
                if(argv[i][j] == 's' && flag_s == OFF)
                {
                    flag_s = ON;
                }
                if(argv[i][j] == 'S' && flag_S == OFF)
                {
                    flag_S = ON;
                }
                if(argv[i][j] == 't' && flag_t == OFF)
                {
                    flag_t = ON;
                }
                if(argv[i][j] == 'x' && flag_x == OFF)
                {
                    flag_x = ON;
                }

                j++;
            }
        }
    }

    if(flag_O == ON)
        flag_n = OFF;

    if(flag_F == OFF)
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
        encode_shift(new_string); 
        node = head;
        free_list(node);    

        int encode_val = encode_shift(new_string);
        decoded_value = to_decode(encode_val);
        main_string = decoded_string(new_string, decoded_value, file_sz);
        letters = letter_count(main_string);
        freq_table = get_frequency_table(main_string);

        if(flag_O == ON)
        {
            if(flag_O == OFF)
            {   
                if(flag_n == OFF)
                {
                    if(flag_s == ON)
                    {
                        printf("Decode shift: %d\n", decoded_value);
                    }
                    if(flag_S == ON)
                    {
                        printf("Encode shift: %d\n", encode_val);
                    }
                    if(flag_t == ON)
                    {
                        /* Print letter count */
                        printf("Letter count: %d\n", letters);
                        /* Print frequency table */
                        print_frequency_table(freq_table);
                    }
                    if(flag_x == ON)
                    {
                        print_chi_vals(new_string);
                    }

                    printf("%s\n", main_string);
                }
                else if(flag_n == ON)
                {
                    if(flag_s == ON)
                    {
                        printf("Decode shift: %d\n", decoded_value);
                    }
                    if(flag_S == ON)
                    {
                        printf("Encode shift: %d\n", encode_val);
                    }
                    if(flag_t == ON)
                    {
                        /* Print letter count */
                        printf("Letter count: %d\n", letters);
                        /* Print frequency table */
                        print_frequency_table(freq_table);
                    }
                    if(flag_x == ON)
                    {
                        print_chi_vals(new_string);
                    }
                }
                
            }            
            else if(flag_O == ON)
            {   
                if(flag_n == ON)
                    flag_n = OFF;

                if(flag_s == ON)
                {
                    printf("Decode shift: %d\n", decoded_value);
                }
                if(flag_S == ON)
                {
                    printf("Encode shift: %d\n", encode_val);
                }
                if(flag_t == ON)
                {
                    /* Print letter count */
                    printf("Letter count: %d\n", letters);
                    /* Print frequency table */
                    print_frequency_table(freq_table);
                }
                if(flag_x == ON)
                {
                    print_chi_vals(new_string);
                }
                output_fp = fopen(output_file, "w+");
                fprintf(output_fp, "%s", main_string);

                fclose(output_fp);
            }
        }

    }
    if(flag_F == ON)
    {
        i = 0;

        fp = fopen(input_file, "r");

        if(fp == NULL)
        {
            printf("Cannot open file %s\n", input_file);
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

            int encode_val = encode_shift(new_string);
            decoded_value = to_decode(encode_val);
            main_string = decoded_string(new_string, decoded_value, file_sz);
            letters = letter_count(main_string);
            freq_table = get_frequency_table(main_string);
            
            if(flag_O == OFF)
            {   
                if(flag_n == OFF)
                {
                    if(flag_s == ON)
                    {
                        printf("Decode shift: %d\n", decoded_value);
                    }
                    if(flag_S == ON)
                    {
                        printf("Encode shift: %d\n", encode_val);
                    }
                    if(flag_t == ON)
                    {
                        /* Print letter count */
                        printf("Letter count: %d\n", letters);
                        /* Print frequency table */
                        print_frequency_table(freq_table);
                    }
                    if(flag_x == ON)
                    {
                        print_chi_vals(new_string);
                    }

                    printf("%s\n", main_string);
                }
                else if(flag_n == ON)
                {
                    if(flag_s == ON)
                    {
                        printf("Decode shift: %d\n", decoded_value);
                    }
                    if(flag_S == ON)
                    {
                        printf("Encode shift: %d\n", encode_val);
                    }
                    if(flag_t == ON)
                    {
                        /* Print letter count */
                        printf("Letter count: %d\n", letters);
                        /* Print frequency table */
                        print_frequency_table(freq_table);
                    }
                    if(flag_x == ON)
                    {
                        print_chi_vals(new_string);
                    }
                }
                
            }            
            else if(flag_O == ON)
            {   
                if(flag_n == ON)
                    flag_n = OFF;

                if(flag_s == ON)
                {
                    printf("Decode shift: %d\n", decoded_value);
                }
                if(flag_S == ON)
                {
                    printf("Encode shift: %d\n", encode_val);
                }
                if(flag_t == ON)
                {
                    /* Print letter count */
                    printf("Letter count: %d\n", letters);
                    /* Print frequency table */
                    print_frequency_table(freq_table);
                }
                if(flag_x == ON)
                {
                    print_chi_vals(new_string);
                }
                output_fp = fopen(output_file, "w+");
                fprintf(output_fp, "%s", main_string);

                fclose(output_fp);
            }

        }
    }


    
    return 0;
}

