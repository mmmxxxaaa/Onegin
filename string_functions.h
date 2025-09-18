#ifndef MY_STRING_FUNCTIONS_H_
#define MY_STRING_FUNCTIONS_H_

#include <stdio.h>

void StrswapGovno(char* temp, char* str_first, char* str_second);
void StrswapBykva(char* str_first, char* str_second);
void StrswapPachka(char* str_first, char* str_second);

int MyFputs(const char* string, FILE* stream);
int CountLines(char* text_buffer);


#endif // MY_STRING_FUNCTIONS_H_
