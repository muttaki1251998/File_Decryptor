#include "header.h"


int main(int argc, char *argv[])
{   
    FILE *fp, *ofp, *text_fp;
    Node *node = NULL, *head = NULL;
    Records rec;
    char fc;
    int i = 0, j = 0;
    int _encoded_shift = 0, _decode_shift = 0;
    int num_records = 0;
    int f_size = 0;
    char *temp_string1, *temp_string2;
    int file_sz = 0;


    if(argc > 8)
    {
        printf("Too many arguments.\n");
    }
    
    char *input_file = NULL;
    char *output_file = NULL;
    char *encode_file = NULL;
    int flag_F = OFF, flag_O = OFF, flag_D = OFF, flag_r = OFF;
    
    for(i=1; i<argc; i++)
    {   
        if(argv[i][0] == '-')
        {           
            if(argv[i][1] == 'F' && flag_F == OFF)
            {
                flag_F = ON;                    
                input_file = malloc(sizeof(char) * strlen(argv[i+1]));                   
                strcpy(input_file, argv[i+1]);
            }
            if(argv[i][1] == 'O' && flag_O == OFF)
            {
                flag_O = ON;                
                output_file = malloc(sizeof(char) * strlen(argv[i+1]));                
                strcpy(output_file, argv[i+1]);
            }
            if(argv[i][1] == 'D' && flag_D == OFF)
            {
                flag_D = ON;                
                encode_file = malloc(sizeof(char) * strlen(argv[i+1]));                
                strcpy(encode_file, argv[i+1]);
            }
            if(argv[i][1] == 'r' && flag_r == OFF)
            {
                flag_r = ON;
            }
            
        }         
    }

    if(flag_F == OFF)
    {
        printf("-F missing. Program terminating...\n");
        exit(1);
    }

    if(flag_F == ON && flag_O == ON)
    {

        i = 0;
        /* Getting the shift value from text file */
        text_fp = fopen(encode_file, "r");

        if(text_fp == NULL)
        {
            printf("Cannot open file\n");
            exit(1);
        } 

        while( (fc=fgetc(text_fp)) != EOF )
        {
            file_sz++;
            node = add_input(head, fc);
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
        node = head;
        free_list(node);
        fclose(text_fp);
        

        _encoded_shift = encode_shift(new_string);
        _decode_shift = to_decode(_encoded_shift);  

        
        fp = fopen(input_file, "rb");
        if(fp != NULL)
        {
            f_size = file_size(fp);
            num_records = f_size / sizeof(Records);
        }

        /* printf("Number of records: %d\n", num_records); */
        ofp = fopen(output_file, "w+");
        if(ofp == NULL)
        {
            printf("Cannot open file\n");
            exit(1);
        }
        j = 0;
        for(i=0; i<num_records; i++)
        {
            fseek(fp, sizeof(Records)*i, SEEK_SET);
            fread(rec.string1, sizeof(char) , 24, fp);
            temp_string1 = decoded_string(rec.string1, _decode_shift, 24);
            fread(rec.d_value, sizeof(double), 24, fp);
            fread(rec.string2, sizeof(char), 144, fp);
            temp_string2 = decoded_string(rec.string2, _decode_shift, 144); 
            fread(rec.int_value, sizeof(int), 12, fp);

            fprintf(ofp, "%s", temp_string1);
            for(j=0; j<24; j++)
                fprintf(ofp, "%lf", rec.d_value[j]);       
            fprintf(ofp, "%s", temp_string2);
            for(j=0; j<12; j++)
                fprintf(ofp, "%d", rec.int_value[j]); 
            fprintf(ofp, "\n");       
        }

    }

    if(flag_O == ON && flag_r == ON)
    {
         i = 0;
        /* Getting the shift value from text file */
        text_fp = fopen(encode_file, "r");

        if(text_fp == NULL)
        {
            printf("Cannot open file\n");
            exit(1);
        } 

        while( (fc=fgetc(text_fp)) != EOF )
        {
            file_sz++;
            node = add_input(head, fc);
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
        node = head;
        free_list(node);
        fclose(text_fp);
        

        _encoded_shift = encode_shift(new_string);
        _decode_shift = to_decode(_encoded_shift);  
        printf("%d\n", _decode_shift);
        
        fp = fopen(input_file, "rb");
        if(fp != NULL)
        {
            f_size = file_size(fp);
            num_records = f_size / sizeof(Records);
        }

        printf("Number of records: %d\n", num_records);

        ofp = fopen(output_file, "w+");
        if(ofp == NULL)
        {
            printf("Cannot open file\n");
            exit(1);
        }
        j = 0;
        for(i=1; i<=num_records; i++)
        {
            fseek(fp, sizeof(Records)*-i, SEEK_END);
            fread(rec.string1, sizeof(char) , 24, fp);
            temp_string1 = decoded_string(rec.string1, _decode_shift, 24);
            fread(rec.d_value, sizeof(double), 24, fp);
            fread(rec.string2, sizeof(char), 144, fp);
            temp_string2 = decoded_string(rec.string2, _decode_shift, 144); 
            fread(rec.int_value, sizeof(int), 12, fp);

            fprintf(ofp, "%s", temp_string1);
            for(j=0; j<24; j++)
                fprintf(ofp, "%lf", rec.d_value[j]);       
            fprintf(ofp, "%s", temp_string2);
            for(j=0; j<12; j++)
                fprintf(ofp, "%d", rec.int_value[j]);         
        }
    }

    if(flag_F == ON && flag_O == OFF)
    {
        i = 0;
        /* Getting the shift value from text file */
        text_fp = fopen(encode_file, "r");

        if(text_fp == NULL)
        {
            printf("Cannot open file %s\n", encode_file);
            exit(1);
        } 

        while( (fc=fgetc(text_fp)) != EOF )
        {
            file_sz++;
            node = add_input(head, fc);
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
        node = head;
        free_list(node);
        fclose(text_fp);
        

        _encoded_shift = encode_shift(new_string);
        _decode_shift = to_decode(_encoded_shift);  
        
        
        fp = fopen(input_file, "rb");
        if(fp != NULL)
        {
            f_size = file_size(fp);
            num_records = f_size / sizeof(Records);
        }

        
        j = 0;
        for(i=0; i<num_records; i++)
        {
            fseek(fp, sizeof(Records)*i, SEEK_SET);
            fread(rec.string1, sizeof(char) , 24, fp);
            temp_string1 = decoded_string(rec.string1, _decode_shift, 24);
            fread(rec.d_value, sizeof(double), 24, fp);
            fread(rec.string2, sizeof(char), 144, fp);
            temp_string2 = decoded_string(rec.string2, _decode_shift, 144); 
            fread(rec.int_value, sizeof(int), 12, fp);

            fprintf(stdout, "%s", temp_string1);
            for(j=0; j<24; j++)
                fprintf(stdout, "%lf", rec.d_value[j]);       
            fprintf(stdout, "%s", temp_string2);
            for(j=0; j<12; j++)
                fprintf(stdout, "%d", rec.int_value[j]);    
            fprintf(stdout, "\n");       
        }
    }

    return 0;
    
}