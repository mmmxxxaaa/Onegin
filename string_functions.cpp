#include "string_functions.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "casting_functions.h"

void StrswapGovno(char* temp, char* str_first, char* str_second)
{
    assert(temp != NULL);
    assert(str_first != NULL);
    assert(str_second != NULL);

    strcpy(temp, str_first);
    strcpy(str_first, str_second);
    strcpy(str_second, temp);
}

void StrswapBykva(char* str_first, char* str_second)
{
    assert(str_first != NULL);
    assert(str_second != NULL);

    char tmp = '\0';
    int flag = 0;

    for (int i = 0; flag < 2; i++)
    {
        tmp = *str_first;

        if (tmp == '\n')
            flag += 1;

        *str_first = *str_second;

        if (*str_first == '\n')
            flag += 1;

        *str_second = tmp;

        if (flag == 2)
            break;

        str_first++;
        str_second++;
    }
}

void StrswapPachka(char* str_first, char* str_second)
{
    assert(str_first != NULL);
    assert(str_second != NULL);

    int tmp_int = 0;

    char* newline_char_first = strchr(str_first, '\n');
    char* newline_char_second = strchr(str_second, '\n');
    if (newline_char_first == NULL || newline_char_second == NULL)
    {
        printf("There is no \\n symbol in the string\n");
        //return -1;
    }

    long int end_pos_first = newline_char_first + 1 - str_first; //находим индекс \n strlen
    long int end_pos_second = newline_char_second + 1 - str_second;

    long int max_pos = (end_pos_first > end_pos_second)? end_pos_first : end_pos_second;

    long unsigned int int_iterations = I64ToU64SafeCast(max_pos) / sizeof(int);
    long int char_iterations = I64ToU64SafeCast(max_pos) % sizeof(int);

    for (long unsigned int i = 0; i < int_iterations; i++)
    {
        tmp_int = *((int*) str_first);
        *((int*) str_first) = *((int*) str_second);
        *((int*) str_second) = tmp_int;

        str_first += sizeof(int);
        str_second += sizeof(int);
    }

    char tmp_char = 0;
    for (int j = 0; j < char_iterations; j++)
    {
        tmp_char = *str_first;
        *str_first = *str_second;

        *str_second = tmp_char;

        str_first++;
        str_second++;
    }
}

int CountLines(char* text_buffer)
{
    assert(text_buffer != NULL);

    int counter = 0;
    char* current_pointer = text_buffer;

    for(;;)
    {
        current_pointer = strchr(text_buffer, '\n');
        if (current_pointer == NULL)
            break;
        counter++;
        text_buffer = current_pointer + 1;
    }

    return counter;
}
