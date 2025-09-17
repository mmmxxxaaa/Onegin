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

    long int amount_of_symbols = GetAmountOfSymbols(input_file);

    char* all_in_string = (char*) calloc(amount_of_symbols + 1, sizeof(char));
    ssize_t success_read_symbols = ReadSymbolsFromFile(all_in_string, amount_of_symbols, input_file);
    if (success_read_symbols == -1)
    {
        fprintf(stderr, "Failed reading symbols from file");
        return -1;
    }
    fclose(input_file);

    int amount_of_lines = CountLines(all_in_string);
    string_info* pointers_to_lines = (string_info*) calloc(amount_of_lines + 1, sizeof(string_info));
    if (pointers_to_lines == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }

    GetStringPointers(all_in_string, pointers_to_lines, success_read_symbols, amount_of_lines);
    char** copied_pointers_to_lines = (char**) calloc(amount_of_lines + 1, sizeof(char* )); //на 1 элемент больше, чтобы в конце массива всегда был нулевой указатель
    memcpy(copied_pointers_to_lines, pointers_to_lines, (amount_of_lines + 1) * sizeof(char*));

    BubbleSort(pointers_to_lines, amount_of_lines, MyStrcmp);   //FIXME
    OutputFromPointers(amount_of_lines, pointers_to_lines);

    qsort(pointers_to_lines, amount_of_lines, sizeof(string_info), MyStrcmpReversed);
    OutputFromPointers(amount_of_lines, pointers_to_lines);

    free(copied_pointers_to_lines);
    free(all_in_string);
    free(pointers_to_lines);
    return 0;
}
