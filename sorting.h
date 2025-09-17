#ifndef SORTING_H_
#define SORTING_H_

#include "io.h"

int MyStrcmp(StringInfo string_1, StringInfo string_2);
int MyStrcmpReversed(const void* string_1, const void* string_2);
int MyStrcmpLen(StringInfo string_1, StringInfo string_2);

void BubbleSort(StringInfo* pointers_to_lines, int amount_of_lines, int (*comparator)(StringInfo string_1, StringInfo string_2));
void SwapPointers(StringInfo* string_1, StringInfo* string_2);


#endif // SORTING_H_
