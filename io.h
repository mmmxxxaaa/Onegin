#ifndef IO_H_
#define IO_H_

#include <stdio.h>

typedef struct {

    char* ptr_to_beginning;
    int length;

} string_info;


void output_from_pointers(int amount_of_lines, string_info* pointers_to_lines);
void get_string_pointers(char* all_in_string, string_info* pointers_to_lines, long int amount_of_symbols, int max_lines);




#endif // IO_H_
