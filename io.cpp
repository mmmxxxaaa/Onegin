#include "io.h"

#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "string_functions.h"

void OutputFromPointers(FILE* output_file, int amount_of_lines, StringInfo* pointers_to_lines)
{
    assert(output_file != NULL);
    assert(pointers_to_lines != NULL);

    for (int i = 0; i < amount_of_lines; i++)
    {
        char* current_ptr = (pointers_to_lines[i]).ptr_to_beginning;

        MyFputs(current_ptr, output_file);
        fputc('\n', output_file);
    }
}

void GetStringPointers(FileInfo* file_info)
{
    assert(file_info != NULL);

    (file_info->pointers_to_lines[0]).ptr_to_beginning = file_info->text_buffer;

    int current_line_index = 0; //FIXME иначе сдвиг в .line запомнить запомнить запомнить запомнить!!!!
    int length_of_line = 0;
    for (long int karetka = 0; karetka < file_info->amount_of_symbols; karetka++)
    {
        if (current_line_index >= file_info->amount_of_lines)
            break;

        if (file_info->text_buffer[karetka] == '\n') //MENTOR это же будет долго????
        {
            file_info->pointers_to_lines[current_line_index].length = length_of_line;
            current_line_index++;
            (file_info->pointers_to_lines[current_line_index]).ptr_to_beginning = &(file_info->text_buffer[karetka + 1]);
            length_of_line = 0;
        }
        else
            length_of_line += 1;
    }
}

char* GetNameOfFile(int argc, char* argv[], int index_of_filename)
{
    assert(argv != NULL);

    if (argc <= index_of_filename)
    {
        fprintf(stderr, "Failed reading command string argument: \n");
        return NULL;
    }
    return argv[index_of_filename];
}

long int GetAmountOfSymbols(FILE *input_file)
{
    assert(input_file != NULL);

    int file_descriptor = fileno(input_file); //получили файловый дескриптор
    struct stat about_file;
    fstat(file_descriptor, &about_file);

    return about_file.st_size;
}

ssize_t ReadSymbolsFromFile(char* text_buffer, long int amount_of_symbols, FILE* input_file)
{
    assert(input_file != NULL);

    if (text_buffer == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }

    long int success_read_symbols = fread(text_buffer, sizeof(char), amount_of_symbols, input_file);
    text_buffer[amount_of_symbols] = '\0';
    if (amount_of_symbols != success_read_symbols)
    {
        fprintf(stderr, "Failed reading symbols\n");
        return -1;
    }
    return success_read_symbols;
}

void FreeStructFileInfo(FileInfo *file_info)
{
    free(file_info->text_buffer);
    free(file_info->pointers_to_lines);
}
