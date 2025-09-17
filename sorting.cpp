#include "sorting.h"

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include "string_functions.h"
#include "io.h"

int my_strcmp(string_info string_1, string_info string_2)
{
    char* current_pointer_1 = string_1.ptr_to_beginning;
    char* current_pointer_2 = string_2.ptr_to_beginning;

    while (!isalpha(*current_pointer_1))
        current_pointer_1 += 1;

    while (!isalpha(*current_pointer_2))
        current_pointer_2 += 1;

    while (*current_pointer_1 != '\n' && *current_pointer_1 == *current_pointer_2)
    {
        current_pointer_1 += 1;
        current_pointer_2 += 1;
    }
    if (*current_pointer_1 > *current_pointer_2)
        return 1;
    if (*current_pointer_1 < *current_pointer_2)
        return -1;
    return 0;
}
//FIXME заглавные и строчные буквы должны восприниматься одинаково
int my_strcmp_reversed(const void* ptr_string_1, const void* ptr_string_2)
{
    string_info string_1 = *((string_info*) ptr_string_1);
    string_info string_2 = *((string_info*) ptr_string_2);

    //чтобы не гонять по указателю каждый раз нужно создать копию структуры


    int length_1 = string_1.length;
    int length_2 = string_2.length;

    char* current_pointer_1 = string_1.ptr_to_beginning + length_1 - 1;
    char* current_pointer_2 = string_2.ptr_to_beginning + length_2 - 1;
    char* beginning_pointer_1 = string_1.ptr_to_beginning;
    char* beginning_pointer_2 = string_2.ptr_to_beginning;

    while (current_pointer_1 >= beginning_pointer_1 && !isalpha(*current_pointer_1))
        current_pointer_1 -= 1;
    while (current_pointer_2 >= beginning_pointer_2 && !isalpha(*current_pointer_2))
        current_pointer_2 -= 1;

    while (current_pointer_1 >= beginning_pointer_1 && current_pointer_2 >= beginning_pointer_2)
    {
        if (*current_pointer_1 != *current_pointer_2)
            return (*current_pointer_1 > *current_pointer_2) ? 1 : -1;

        current_pointer_1 -= 1;
        current_pointer_2 -= 1;

        while (current_pointer_1 >= beginning_pointer_1 && !isalpha(*current_pointer_1))
            current_pointer_1 -= 1;       //
        while (current_pointer_2 >= beginning_pointer_2 && !isalpha(*current_pointer_2))
            current_pointer_2 -= 1;       //
    }

    if (current_pointer_1 < beginning_pointer_1 && current_pointer_2 < beginning_pointer_2)
        return 0;
    if (current_pointer_1 < beginning_pointer_1)
        return -1;
    return 1;
}

int my_strcmp_len(string_info string_1, string_info string_2)
{
    if (string_1.length > string_2.length)
        return 1;
    if (string_1.length < string_2.length)
        return -1;
    return 0;
}

void bubble_sort(string_info* pointers_to_lines, int amount_of_lines, int (*comparator)(string_info string_1, string_info string_2)) //FIXME тайпдефнуть
{
    assert(pointers_to_lines != NULL);
    assert(comparator != NULL);

    if (amount_of_lines <= 1)
        return; //случай, когда массив пустой или состоит из одного элемента

    int swapped = 0;
    for (int i = 0; i < amount_of_lines - 1; i++) //FIXME убрал -1
    {
        swapped = 0;
        for (int j = 0; j < amount_of_lines - i - 1; j++) //FIXME убрал -1
        {
            if (comparator(pointers_to_lines[j], pointers_to_lines[j + 1]) == 1)
            {
                swap_pointers(&(pointers_to_lines[j]), &(pointers_to_lines[j + 1]));
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void swap_pointers(string_info* string_1, string_info* string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    string_info tmp = *string_2;
    *string_2 = *string_1;
    *string_1 = tmp;
}
//
// //FIXME БЫЛО ТАК разобраться с функцией свапа
// void swap_pointers(string_info* string_1, string_info* string_2)
// {
//     assert(string_1 != NULL);
//     assert(string_2 != NULL);
//
//     string_info* tmp = string_2;
//     string_2 = string_1;
//     string_1 = tmp;
// }
