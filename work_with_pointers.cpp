#include "work_with_pointers.h"

void get_string_pointers(char* all_in_string, char** pointers_to_lines, long int amount_of_symbols)
{
    pointers_to_lines[0] = all_in_string;

    int counter = 1;
    for (long int karetka = 0; karetka < amount_of_symbols; karetka++)
    {
        if (all_in_string[karetka] == '\n')
        {
            pointers_to_lines[counter] = &all_in_string[karetka + 1];
            counter++;
        }
    }
}
