#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "string_functions.h"
#include "io.h"
#include "sorting.h"

#include "string.h"

int main()
{
    FILE* input_file = fopen("Onegin.txt", "r");
    if (input_file == NULL)
    {
        printf("Cannot open the file \"Onegin.txt\"\n");
        return -1;
    }

    int file_descriptor = fileno(input_file); //получили файловый дескриптор
    struct stat about_file;
    fstat(file_descriptor, &about_file);
    long int amount_of_symbols = about_file.st_size;

    // char strings[15][42] = {0};  //42 = 40 + '\n' + '\0'
    char* all_in_string = (char*) calloc(amount_of_symbols + 1, sizeof(char));     //неужели нужно в int всё хранить, чтобы EOF можно было прочитать?
    if (all_in_string == NULL)
    {
        printf("Cannot allocate memory\n");
        return -1;
    }
    all_in_string[amount_of_symbols] = '\0';

    size_t read_symbols = fread(all_in_string, sizeof(char), amount_of_symbols, input_file);

    int amount_of_lines = count_lines(all_in_string);

    // char** pointers_to_lines = (char**) calloc(amount_of_lines + 1, sizeof(char* )); //на 1 элемент больше, чтобы в конце массива всегда был нулевой указатель
    //FIXME
    string_info* pointers_to_lines = (string_info*) calloc(amount_of_lines + 1, sizeof(string_info));

    if (pointers_to_lines == NULL)
    {
        printf("Cannot allocate memory\n");
        return -1;
    }
    get_string_pointers(all_in_string, pointers_to_lines, read_symbols, amount_of_lines);

    char** copied_pointers_to_lines = (char**) calloc(amount_of_lines + 1, sizeof(char* )); //на 1 элемент больше, чтобы в конце массива всегда был нулевой указатель
    memcpy(copied_pointers_to_lines, pointers_to_lines, (amount_of_lines + 1) * sizeof(char*));

    bubble_sort(pointers_to_lines, amount_of_lines, my_strcmp);   //FIXME

    output_from_pointers(amount_of_lines, pointers_to_lines);
    printf("%d\nsudaaaaaaaaaaaaaaaaaa\n", amount_of_lines); //5311 или 5312?

    free(copied_pointers_to_lines);
    free(all_in_string);
    free(pointers_to_lines);
    fclose(input_file);
    return 0;
}
