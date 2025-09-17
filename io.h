#ifndef IO_H_
#define IO_H_

#include <stdio.h>

typedef struct {

    char* ptr_to_beginning;
    int length;

} string_info;

typedef struct {
    int amount_of_lines;
    long int amount_of_symbols;
    char* all_in_string;
    string_info* pointers_to_lines;
} FileInfo;

void OutputFromPointers(int amount_of_lines, string_info* pointers_to_lines);
void GetStringPointers(char* all_in_string, string_info* pointers_to_lines, long int amount_of_symbols, int max_lines);
long int GetAmountOfSymbols(FILE* input_file);
ssize_t ReadSymbolsFromFile(char* all_in_string, long int amount_of_symbols, FILE* input_file);

#endif // IO_H_
