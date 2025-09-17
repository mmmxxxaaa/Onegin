#ifndef MY_STRING_FUNCTIONS_H_
#define MY_STRING_FUNCTIONS_H_

#include <stdio.h>

void strswap_govno(char* temp, char* str_first, char* str_second);
void strswap_bykva(char* str_first, char* str_second);
void strswap_pachka(char* str_first, char* str_second);

int my_fputs(const char* string, FILE* stream);
int CountLines(char* all_in_string);


#endif // MY_STRING_FUNCTIONS_H_
