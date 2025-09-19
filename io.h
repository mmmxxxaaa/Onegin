#ifndef IO_H_
#define IO_H_

#include <stdio.h>

typedef struct {
    char* ptr_to_beginning;
    int length;
} StringInfo;

typedef struct {
    int number_of_lines;
    long int number_of_symbols;
    char* text_buffer;
    StringInfo* pointers_to_lines;
} FileInfo;

void OutputFromPointers(FILE* output_file, int number_of_lines, StringInfo* pointers_to_lines);
void GetStringPointers(FileInfo* file_info);
// char* GetNameOfFile(int argc, char* argv[], int index_of_filename);
long int GetAmountOfSymbols(FILE* input_file);
ssize_t ReadSymbolsFromFile(char* text_buffer, long int number_of_symbols, FILE* input_file);
void FreeStructFileInfo(FileInfo *file_info);
size_t MyFputs(const char* string, FILE* stream); // ДЕЛО СДЕЛАНО - Вывод в функциях для работы со строками?(поменял)

#endif // IO_H_
