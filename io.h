#ifndef IO_H_
#define IO_H_

#include <stdio.h>

typedef struct {

    char* ptr_to_beginning;
    int length;

} StringInfo;

typedef struct {
    int amount_of_lines;
    long int amount_of_symbols;
    char* all_in_string;
    StringInfo* pointers_to_lines;
} FileInfo;

void OutputFromPointers(int amount_of_lines, StringInfo* pointers_to_lines);
void GetStringPointers(char* all_in_string, StringInfo* pointers_to_lines, long int amount_of_symbols, int max_lines);
int GetNameOfFile(char* ptr_filename, int name_size, int argc, char* argv[]);
long int GetAmountOfSymbols(FILE* input_file);
ssize_t ReadSymbolsFromFile(char* all_in_string, long int amount_of_symbols, FILE* input_file);

#endif // IO_H_
