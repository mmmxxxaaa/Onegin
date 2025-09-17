#include "sorting.h"

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include "string_functions.h"
#include "io.h"

int my_strcmp(const char* string_1, const char* string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    while (!isalpha(*string_1))
        string_1++;

    while (!isalpha(*string_2))
        string_2++;

    while (*string_1 != '\n' && *string_1 == *string_2)
    {
        string_1++;
        string_2++;
    }
    if (*string_1 > *string_2)
        return 1;
    if (*string_1 < *string_2)
        return -1;
    return 0;
}

int my_strcmp_len(const char* string_1, const char* string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    const char* address_1 = strchr(string_1, '\n');
    const char* address_2 = strchr(string_2, '\n');
    long int length_1 = address_1 - string_1;
    long int length_2 = address_2 - string_2;

    if (length_1 > length_2)
        return 1;
    if (length_1 < length_2)
        return -1;
    return 0;
}

void bubble_sort(string_info* pointers_to_lines, int amount_of_lines, int (*comparator)(const char* string_1, const char* string_2)) //FIXME тайпдефнуть
{
    assert(pointers_to_lines != NULL);
    assert(comparator != NULL);

    if (amount_of_lines <= 1)
        return; //случай, когда массив пустой или состоит из одного элемента

    int swapped = 0;
    for (int i = 0; i < amount_of_lines - 1; i++) //FIXME убрал -1
    {
        // printf("penis\n");
        swapped = 0;
        for (int j = 0; j < amount_of_lines - i - 1; j++) //FIXME убрал -1
        {
            // printf("xyi %d\n", j);
            if (comparator((pointers_to_lines[j]).ptr_to_beginning, (pointers_to_lines[j + 1]).ptr_to_beginning) == 1)
            {
                // printf("check string\n");
                // printf("%s\n", pointer_to_pointers_to_lines[j]);
                // my_fputs(pointers_to_lines[j], stdout);
                // my_fputs(pointers_to_lines[j+1], stdout);
                // printf("swapped\n");
                swap_pointers(&((pointers_to_lines[j]).ptr_to_beginning), &((pointers_to_lines[j + 1]).ptr_to_beginning));
                swapped = 1;
            }
        }
        // printf("\n");

        if (!swapped)
            break;
    }
}

void swap_pointers(char** string_1, char** string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    char* tmp = *string_2;
    *string_2 = *string_1;
    *string_1 = tmp;
}
