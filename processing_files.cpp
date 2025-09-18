#include "processing_files.h"

#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "errors_codes.h"
#include "string_functions.h"
#include "errors_codes.h"

const int kInputFilenameIndex = 1;
const int kOutputFilenameIndex = 2;

ErrorsCodes ProcessingInputFile(FileInfo* ptr_file_info, char** argv)
{
    char* input_filename = argv[kInputFilenameIndex];

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Cannot open the file \"%s\"\n", input_filename);
        return ERROR_OPENING_FILE;
    }

    ptr_file_info->amount_of_symbols = GetAmountOfSymbols(input_file);

    ptr_file_info->text_buffer = (char*) calloc(ptr_file_info->amount_of_symbols + 1, sizeof(char));
    if (ptr_file_info->text_buffer == NULL)
    {
        fclose(input_file);
        fprintf(stderr, "Cannot allocate memory\n");
        return ERROR_ALLOCATING_MEMORY;
    }
    ssize_t success_read_symbols = ReadSymbolsFromFile(ptr_file_info->text_buffer, ptr_file_info->amount_of_symbols, input_file);
    // fprintf(stderr, "%ld", success_read_symbols);
    if (success_read_symbols == -1)
    {
        free(ptr_file_info->text_buffer);
        fclose(input_file);
        fprintf(stderr, "Failed reading symbols from file");
        return ERROR_READING_FILE;
    }
    fclose(input_file);
    return NO_ERROR;
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

ErrorsCodes ConstructFileInfo(FileInfo* ptr_file_info, char** argv)
{
    ProcessingInputFile(ptr_file_info, argv);

    ptr_file_info->amount_of_lines = CountLines(ptr_file_info->text_buffer);
    ptr_file_info->pointers_to_lines = (StringInfo*) calloc(ptr_file_info->amount_of_lines + 1, sizeof(StringInfo));
    if (ptr_file_info->pointers_to_lines == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return ERROR_ALLOCATING_MEMORY;
    }

    GetStringPointers(ptr_file_info);
    return NO_ERROR;
}
