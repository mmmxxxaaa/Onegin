#ifndef SORTING_H_
#define SORTING_H_

#include "io.h"

int MyStrcmp(string_info string_1, string_info string_2);
int MyStrcmpReversed(const void* string_1, const void* string_2);
int MyStrcmpLen(string_info string_1, string_info string_2);

void BubbleSort(string_info* pointers_to_lines, int amount_of_lines, int (*comparator)(string_info string_1, string_info string_2));
void SwapPointers(string_info* string_1, string_info* string_2);


#endif // SORTING_H_
