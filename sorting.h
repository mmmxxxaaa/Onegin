#ifndef SORTING_H_
#define SORTING_H_

#include "io.h"

typedef int (*Comparator)(StringInfo string_1, StringInfo string_2);

int MyStrcmp(StringInfo string_1, StringInfo string_2);
int MyStrcmpReversed(const void* string_1, const void* string_2);
int MyStrcmpLen(StringInfo string_1, StringInfo string_2);

void BubbleSort(StringInfo* pointers_to_lines, int number_of_lines, Comparator comparator);
void SwapPointers(StringInfo* string_1, StringInfo* string_2);


#endif // SORTING_H_
