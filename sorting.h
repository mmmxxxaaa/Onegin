#ifndef SORTING_H_
#define SORTING_H_

int my_strcmp(const char* string_1, const char* string_2);
int my_strcmp_len(const char* string_1, const char* string_2);

void bubble_sort(char** pointers_to_lines, int amount_of_lines, int (*comparator)(const char* string_1, const char* string_2));
void swap_pointers(char** string_1, char** string_2);


#endif // SORTING_H_
