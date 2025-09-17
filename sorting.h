#ifndef SORTING_H_
#define SORTING_H_

#include "io.h"

int my_strcmp(string_info string_1, string_info string_2);
int my_strcmp_len(string_info string_1, string_info string_2);

void bubble_sort(string_info* pointers_to_lines, int amount_of_lines, int (*comparator)(string_info string_1, string_info string_2));
void swap_pointers(string_info* string_1, string_info* string_2);


#endif // SORTING_H_
