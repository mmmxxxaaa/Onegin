#include "io.h"

#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>

#include "string_functions.h"

void OutputFromPointers(int amount_of_lines, StringInfo* pointers_to_lines) //неважно, что в исходном массиве указатели уже в другом порядке, ведь в этот массив передаём копированную версию изначлаьного указателя
{
    assert(pointers_to_lines != NULL);

    for (int i = 0; i < amount_of_lines; i++)
    {
        char* current_ptr = (pointers_to_lines[i]).ptr_to_beginning;

        MyFputs(current_ptr, stdout);
        printf("\n");
    }
}

void GetStringPointers(FileInfo* file_info) //ДЕЛО СДЕЛАНО
{
    assert(file_info != NULL);

    (file_info->pointers_to_lines[0]).ptr_to_beginning = file_info->all_in_string;

    int current_line_index = 0; //FIXME иначе сдвиг в .line запомнить запомнить запомнить запомнить!!!!
    int length_of_line = 0;
    for (long int karetka = 0; karetka < file_info->amount_of_symbols; karetka++)
    {
        if (current_line_index >= file_info->amount_of_lines) //FIXME почему без этого не работает
            break;
        if (file_info->all_in_string[karetka] == '\n') //FIXME это же будет долго????
        {
            file_info->pointers_to_lines[current_line_index].length = length_of_line;
            current_line_index++;
            (file_info->pointers_to_lines[current_line_index]).ptr_to_beginning = &(file_info->all_in_string[karetka + 1]);
            length_of_line = 0;
        }
        else
            length_of_line += 1;
    }
    // my_fputs(pointers_to_lines[0].ptr_to_beginning, stdout);
}

int GetNameOfFile(char* ptr_filename, int name_size, int argc, char* argv[])
{
    assert(ptr_filename != NULL);

    if (argc != 2)
    {
        fprintf(stderr, "Failed reading command string argument: \n");
        return 0;
    }
    else
    {
        strncpy(ptr_filename, argv[1], name_size - 1);
        ptr_filename[name_size - 1] = '\0';
    }
    return 1;
}

long int GetAmountOfSymbols(FILE *input_file)
{
    assert(input_file != NULL);

    int file_descriptor = fileno(input_file); //получили файловый дескриптор
    struct stat about_file;
    fstat(file_descriptor, &about_file);
    return about_file.st_size;
}

ssize_t ReadSymbolsFromFile(char* all_in_string, long int amount_of_symbols, FILE* input_file)
{
    assert(input_file != NULL);

    if (all_in_string == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }
    all_in_string[amount_of_symbols] = '\0';
    return fread(all_in_string, sizeof(char), amount_of_symbols, input_file);
}

//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ Проблема была в следующем: после сортировки указатели в массиве pointers_to_lines больше не указывают на последовательные участки памяти и поэтому нах вычисление длины строки как разности между двумя соседними указателями некорректно
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//ХУЙНЯ ПЕРЕДЕЛЫВАЙ запомнить
//     for (int vivodblyat = 0; vivodblyat < amount_of_lines; vivoblyat++)
//     {
//         char* ptr_str1 = pointers_to_lines[vivoblyat];
//         char* ptr_str2 = pointers_to_lines[vivoblyat+1];
//
//         for (int index = 0; index < (ptr_str2 - ptr_str1); index++)
//             printf("%c", *(ptr_str1 + index));
//     }

