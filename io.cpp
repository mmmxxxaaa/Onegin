#include "io.h"

#include <stdio.h>
#include <assert.h>


void output_from_pointers(int amount_of_lines, char** pointers_to_lines) //неважно, что в исходном массиве указатели уже в другом порядке, ведь в этот массив передаём копированную версию изначлаьного указателя
{
    assert(pointers_to_lines != NULL);

    for (int i = 0; i < amount_of_lines; i++)
    {
        char* current_ptr = pointers_to_lines[i];
        // Выводим каждый символ до '\n' или '\0'
        while (*current_ptr && *current_ptr != '\n') {
            printf("%c", *current_ptr);
            current_ptr++;
        }
        printf("\n");
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
//     for (int vivodblyat = 0; vivodblyat < amount_of_lines; vivodblyat++)
//     {
//         char* ptr_str1 = pointers_to_lines[vivodblyat];
//         char* ptr_str2 = pointers_to_lines[vivodblyat+1];
//
//         for (int index = 0; index < (ptr_str2 - ptr_str1); index++)
//             printf("%c", *(ptr_str1 + index));
//     }
}
