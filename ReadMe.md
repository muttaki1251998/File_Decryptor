/// Compilation ///
Part One: Frequency Table

To compile part one (Question 1), in your terminal, type:
            make frequency_table
This will compile part one. To run the program, in your terminal, type:
            ./frequency_table or ./frequency_table -F {File_Name}

Part Two:

To compile part two (Question 2), in your terminal, type:
            make decode
This will compile part two. To run the program, in your terminal, type:
            ./decode -F {File_Name} -O {Output_File_Name}

Part 3:

To compile part three (Question 3), in your terminal, type:
            make copy_records
This will compile part three. To run the program, in your terminal, type:  
            ./copy_records....................



/// Functionalities  ///
Part One:
For taking inputs from stdin or taking data from files,the program used linked list to grab data. Linked list takes data character by character. So it stores the data in reverse order. 
That's why the program used a function named reverse_node() to reverse the data and then it stores the data to string variable for further use. The program uses this techinque to take inputs for part 2
and part 3 as well. 
get_frequency_table() takes in the stored data and returns an integer array that contains the frequency of all the letters present in that string. 

Part Two:
The program takes the input the same way it took in part one. It uses the functions encode_shift() to get the minimum chi_sq value from the stored data. Then it uses a to_decode() function to 
get the decode shift that can decrypt the encrypted data. And then my program uses flags to follow the user's commands. 

Part Three:
My program reads an encrypted text file and gets the encrypted shift. From the encrypted ceasar shfit, the program uses to_decode() function to get decode value. Then the program reads in the given binary file, decrypts
the data right after reading a certain amount of bytes, writes the decrypted strings to a file or stdout, all at the same time. The program uses a for-loop to read, decrypt and write to a file/stdout simultaneously.


