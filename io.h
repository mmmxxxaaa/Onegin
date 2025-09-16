#ifndef IO_H_
#define IO_H_

#include <stdio.h>


// void read_chars_from_file(int amount_of_symbols, char* all_in_string, FILE* fp); //передача через char* и char ...[] эквивалентна? Не создается же копия массива при передаче через скобки?
void output_from_pointers(int amount_of_lines, char** pointers_to_lines);



#endif // IO_H_
