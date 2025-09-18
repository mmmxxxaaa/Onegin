#include <stdio.h>
#include <stdlib.h>

#include "string_functions.h"
#include "io.h"
#include "sorting.h"

#include "string.h"

const int kFilenameSize = 100;
const int kInputFilenameIndex = 1;
const int kOutputFilenameIndex = 2;

int main(int argc, char* argv[])
{
    char* input_filename = GetNameOfFile(kFilenameSize, argc, argv, kInputFilenameIndex);
    if (input_filename == NULL)
    {
        fprintf(stderr, "Error reading filename\n");
        return -1;
    }

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        printf("Cannot open the file \"%s\"\n", input_filename);
        return -1;
    }

    FileInfo file_info = {0};
    file_info.amount_of_symbols = GetAmountOfSymbols(input_file);

    file_info.text_buffer = (char*) calloc(file_info.amount_of_symbols + 1, sizeof(char));
    ssize_t success_read_symbols = ReadSymbolsFromFile(file_info.text_buffer, file_info.amount_of_symbols, input_file);
    if (success_read_symbols == -1)
    {
        fprintf(stderr, "Failed reading symbols from file");
        return -1;
    }
    fclose(input_file);

    file_info.amount_of_lines = CountLines(file_info.text_buffer);
    file_info.pointers_to_lines = (StringInfo*) calloc(file_info.amount_of_lines + 1, sizeof(StringInfo)); //массив структур инициализированных нулями
    if (file_info.pointers_to_lines == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }

    GetStringPointers(&file_info); //ДЕЛО СДЕЛАНО указатель на структуру в функцию

    char* output_filename = GetNameOfFile(kFilenameSize, argc, argv, kOutputFilenameIndex);
    if (output_filename == NULL)
    {
        fprintf(stderr, "Error reading filename\n");
        return -1;
    }

    FILE* output_file = fopen(output_filename, "a");
    if (output_file == NULL)
    {
        printf("Cannot open the file \"%s\"\n", output_filename);
        return -1;
    }

    BubbleSort(file_info.pointers_to_lines, file_info.amount_of_lines, MyStrcmp);   //FIXME
    OutputFromPointers(output_file, file_info.amount_of_lines, file_info.pointers_to_lines);

    qsort(file_info.pointers_to_lines, file_info.amount_of_lines, sizeof(StringInfo), MyStrcmpReversed);
    OutputFromPointers(output_file, file_info.amount_of_lines, file_info.pointers_to_lines);

    fprintf(output_file, "%s\n", file_info.text_buffer);

    free(file_info.text_buffer);
    free(file_info.pointers_to_lines);
    return 0;
}
