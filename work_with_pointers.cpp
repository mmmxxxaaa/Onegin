#include "work_with_pointers.h"
#include "io.h" //FIXME нахуй мне отдельный этот файл

void get_string_pointers(char* all_in_string, string_info* pointers_to_lines, long int amount_of_symbols, int max_lines)
{
    (pointers_to_lines[0]).ptr_to_beginning = all_in_string;

    int current_line_index = 1;
    int length_of_line = 0;
    for (long int karetka = 0; karetka < amount_of_symbols; karetka++)
    {
        length_of_line += 1;
        if (current_line_index >= max_lines) //FIXME почему без этого не работает
            break;
        if (all_in_string[karetka] == '\n')
        {
            (pointers_to_lines[current_line_index]).ptr_to_beginning = &all_in_string[karetka + 1];
            current_line_index++;
            (pointers_to_lines[current_line_index]).length = length_of_line;
            length_of_line = 0;
        }

    }
}
