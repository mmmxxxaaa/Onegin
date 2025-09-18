#include <stdio.h>
#include <stdlib.h>

#include "string_functions.h"
#include "io.h"
#include "sorting.h"

#include "string.h"

const int kFilenameSize = 100;

int main(int argc, char* argv[])
{
    char filename[kFilenameSize];
    int success_reading_filename = GetNameOfFile(filename, kFilenameSize, argc, argv);
    if (!success_reading_filename)
    {
        fprintf(stderr, "Error reading filename\n");
        return -1;
    }

    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
        printf("Cannot open the file \"%s\"\n", filename);
        return -1;
    }

    FileInfo file_info = {0};
    file_info.amount_of_symbols = GetAmountOfSymbols(input_file);

    file_info.all_in_string = (char*) calloc(file_info.amount_of_symbols + 1, sizeof(char));
    ssize_t success_read_symbols = ReadSymbolsFromFile(file_info.all_in_string, file_info.amount_of_symbols, input_file);
    if (success_read_symbols == -1)
    {
        fprintf(stderr, "Failed reading symbols from file");
        return -1;
    }
    fclose(input_file);

    file_info.amount_of_lines = CountLines(file_info.all_in_string);
    file_info.pointers_to_lines = (StringInfo*) calloc(file_info.amount_of_lines + 1, sizeof(StringInfo)); //массив структур инициализированных нулями
    if (file_info.pointers_to_lines == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }

    GetStringPointers(&file_info); //ДЕЛО СДЕЛАНО указатель на структуру в функцию
    char** copied_pointers_to_lines = (char**) calloc(file_info.amount_of_lines + 1, sizeof(char* )); //на 1 элемент больше, чтобы в конце массива всегда был нулевой указатель
    memcpy(copied_pointers_to_lines, file_info.pointers_to_lines, (file_info.amount_of_lines + 1) * sizeof(char*));

    BubbleSort(file_info.pointers_to_lines, file_info.amount_of_lines, MyStrcmp);   //FIXME
    OutputFromPointers(file_info.amount_of_lines, file_info.pointers_to_lines);

    qsort(file_info.pointers_to_lines, file_info.amount_of_lines, sizeof(StringInfo), MyStrcmpReversed);
    OutputFromPointers(file_info.amount_of_lines, file_info.pointers_to_lines);

    free(copied_pointers_to_lines);
    free(file_info.all_in_string);
    free(file_info.pointers_to_lines);
    return 0;
}
