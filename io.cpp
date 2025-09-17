#include "io.h"

#include <stdio.h>
#include <assert.h>

#include "string_functions.h"


void output_from_pointers(int amount_of_lines, string_info* pointers_to_lines) //неважно, что в исходном массиве указатели уже в другом порядке, ведь в этот массив передаём копированную версию изначлаьного указателя
{
    assert(pointers_to_lines != NULL);

    for (int i = 0; i < amount_of_lines; i++)
    {
        char* current_ptr = (pointers_to_lines[i]).ptr_to_beginning;

        while (*current_ptr != '\n')
        {
            printf("%c", *current_ptr);
            current_ptr++;
        }
        printf("\n");
    }
}

//FIXME assert
void get_string_pointers(char* all_in_string, string_info* pointers_to_lines, long int amount_of_symbols, int max_lines)
{
    pointers_to_lines[0].ptr_to_beginning = all_in_string;

    int current_line_index = 0; //FIXME иначе сдвиг в .line
    int length_of_line = 0;
    for (long int karetka = 0; karetka < amount_of_symbols; karetka++)
    {
        if (current_line_index >= max_lines) //FIXME почему без этого не работает
            break;
        if (all_in_string[karetka] == '\n')
        {
            pointers_to_lines[current_line_index].length = length_of_line;
            current_line_index++;
            pointers_to_lines[current_line_index].ptr_to_beginning = &all_in_string[karetka + 1];
            length_of_line = 0;
        }
        else
            length_of_line += 1;
    }
    // my_fputs(pointers_to_lines[0].ptr_to_beginning, stdout);
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

