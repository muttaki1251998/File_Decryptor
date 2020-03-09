decode: add_input.o decoded_string.o encode.o encode_shift.o free_list.o get_frequency_table.o letter_count.o offset.o print_chi_val.o print_freq_table.o reverse_node.o to_decode.o decode.c
	gcc -Wall -ansi add_input.o decoded_string.o encode.o encode_shift.o free_list.o get_frequency_table.o letter_count.o offset.o print_chi_val.o print_freq_table.o reverse_node.o to_decode.o decode.c -o decode -lm

frequency_table: letter_count.o get_frequency_table.o add_input.o reverse_node.o free_list.o frequency_table.c
	gcc -Wall -ansi letter_count.o get_frequency_table.o add_input.o reverse_node.o free_list.o frequency_table.c -o frequency_table

copy_records: add_input.o reverse_node.o free_list.o encode.o file_size.o encode_shift.o get_frequency_table.o letter_count.o offset.o to_decode.o decoded_string.o copy_records.c
	gcc -Wall -ansi add_input.o reverse_node.o free_list.o encode.o file_size.o encode_shift.o get_frequency_table.o letter_count.o offset.o to_decode.o decoded_string.o copy_records.c -o copy_records -lm

file_size.o: file_size.c
	gcc -Wall -ansi -c file_size.c

add_input.o: add_input.c
	gcc -Wall -ansi -c add_input.c

decoded_string.o: decoded_string.c
	gcc -Wall -ansi -c decoded_string.c

encode.o: encode.c
	gcc -Wall -ansi -c encode.c

encode_shift.o: encode_shift.c
	gcc -Wall -ansi -c encode_shift.c

free_list.o: free_list.c
	gcc -Wall -ansi -c free_list.c

get_frequency_table.o: get_frequency_table.c
	gcc -Wall -ansi -c get_frequency_table.c

letter_count.o: letter_count.c
	gcc -Wall -ansi -c letter_count.c

offset.o: offset.c
	gcc -Wall -ansi -c offset.c

print_chi_val.o: print_chi_val.c 
	gcc -Wall -ansi -c print_chi_val.c

print_freq_table.o: print_freq_table.o
	gcc -Wall -ansi -c print_freq_table.c

reverse_node.o: reverse_node.c
	gcc -Wall -ansi -c reverse_node.c

to_decode.o: to_decode.c
	gcc -Wall -ansi -c to_decode.c   
	
clean: 
	rm -f *.o decode frequency_table
