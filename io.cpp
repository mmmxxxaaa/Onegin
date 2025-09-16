#include "io.h"

#include <stdio.h>
#include <assert.h>
//fileno


// void read_chars_from_file(int amount_of_symbols, char* all_in_string, FILE* fp)
// {
//     for (long int i = 0; i < amount_of_symbols; i++)
//     {
//         int symbol = getc(fp);
//
//         if (symbol == EOF)
//             break;
//         all_in_string[i] = (char) symbol;
//
//     }
// }


void output_from_pointers(int amount_of_lines, char** pointers_to_lines)
{
    assert(pointers_to_lines != NULL);

    for (int vivodblyat = 0; vivodblyat < amount_of_lines - 1; vivodblyat++) //КАКОГО ХУЯ НАДО ДЕЛАТЬ -1
    {
        char* ptr_str1 = pointers_to_lines[vivodblyat];
        char* ptr_str2 = pointers_to_lines[vivodblyat+1];

        for (int index = 0; index < (ptr_str2 - ptr_str1); index++)
            printf("%c", *(ptr_str1 + index));
    }
}
