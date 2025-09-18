#include "processing_files.h"

#include <stdio.h>
#include <stdlib.h>
#include "io.h"

const int kInputFilenameIndex = 1;
const int kOutputFilenameIndex = 2;

int ProcessingInputFile(FileInfo* ptr_file_info, char** argv)
{
    char* input_filename = argv[kInputFilenameIndex];

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Cannot open the file \"%s\"\n", input_filename);
        return -1;
    }

    ptr_file_info->amount_of_symbols = GetAmountOfSymbols(input_file);

    ptr_file_info->text_buffer = (char*) calloc(ptr_file_info->amount_of_symbols + 1, sizeof(char));
    if (ptr_file_info->text_buffer == NULL)
    {
        fclose(input_file);
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }
    ssize_t success_read_symbols = ReadSymbolsFromFile(ptr_file_info->text_buffer, ptr_file_info->amount_of_symbols, input_file);
    // fprintf(stderr, "%ld", success_read_symbols);
    if (success_read_symbols == -1)
    {
        free(ptr_file_info->text_buffer);
        fclose(input_file);
        fprintf(stderr, "Failed reading symbols from file");
        return -1;
    }
    fclose(input_file);
    return 0;
}

FILE* ProcessingOutputFile(char** argv)
{
    char* output_filename = argv[kOutputFilenameIndex];

    FILE* output_file = fopen(output_filename, "a");
    if (output_file == NULL)
    {
        printf("Cannot open the file \"%s\"\n", output_filename);
        return NULL;
    }

    return output_file;
}
