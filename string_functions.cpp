#include "string_functions.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>



void strswap_govno(char* temp, char* str_first, char* str_second)
{
    assert(temp != NULL);
    assert(str_first != NULL);
    assert(str_second != NULL);

    strcpy(temp, str_first); //FIXME проверка длины (не нужна)
    strcpy(str_first, str_second);
    strcpy(str_second, temp);
}

void strswap_bykva(char* str_first, char* str_second)
{
    assert(str_first != NULL);
    assert(str_second != NULL);

    char tmp = '\0';
    int flag = 0;

    for (int i = 0; flag < 2; i++)
    {
        tmp = *str_first;

        if (tmp == '\n')
            flag += 1;

        *str_first = *str_second;

        if (*str_first == '\n')
            flag += 1;

        *str_second = tmp;

        if (flag == 2)
            break;

        str_first++;
        str_second++;
    }
}


void strswap_pachka(char* str_first, char* str_second)
{
    assert(str_first != NULL);
    assert(str_second != NULL);

    int tmp_int = 0;
//на линуксе просто /n, а в винде /r и /n !!!ИМЕННО В ТАКОМ ПОРЯДКЕ!!!
//файлик создан на винде


    char* newline_char_first = strchr(str_first, '\n');
    char* newline_char_second = strchr(str_second, '\n');
    if (newline_char_first == NULL || newline_char_second == NULL)
    {
        printf("There is no \\n symbol in the string\n");
        //return -1;
    }

    long int end_pos_first = newline_char_first + 1 - str_first; //находим индекс \n strlen
    long int end_pos_second = newline_char_second + 1 - str_second; //FIXME проверить, нашёлся ли вообще \n

    long int max_pos = (end_pos_first > end_pos_second)? end_pos_first : end_pos_second;

    long unsigned int int_iterations = max_pos / sizeof(int);
    long int char_iterations = max_pos % sizeof(int);

    for (long unsigned int i = 0; i < int_iterations; i++)
    {
        tmp_int = *((int*) str_first);   //FIXME вопрос ДЕДУ
        //сначала нужно дойти до адреса кратного четырём побайтово, а потом уже пачками хуярить
        *((int*) str_first) = *((int*) str_second);   //FIXME можно ли через memcpy? Вроде как у нас задание сделать это через явное приведение типов
        *((int*) str_second) = tmp_int;               //FIXME почему так нельзя? Что за "выравнивание"

        str_first += sizeof(int);
        str_second += sizeof(int);
    }

//через это не работает, потому что даже если мы приведём указатель
//к кратному на 4 и потом захотим оставшиеся после передач пачками доведем побайтовыми свапами
//то идея всё равно фигня потому что может быть жёсткий "рассинхрон" указателей
//типа если один будет делиться на 4 с остатком 3, а другой с остатком 1, то всё пипиец


//memmove хайповее memcpy
    char tmp_char = 0;
    for (int j = 0; j < char_iterations; j++)
    {
        tmp_char = *str_first;
        *str_first = *str_second;

        *str_second = tmp_char;

        str_first++;
        str_second++;
    }
}


int count_lines(char* all_in_string)
{
    assert(all_in_string != NULL);

    int counter = 0;
    char* current_pointer = all_in_string;

    for(;;)
    {
        current_pointer = strchr(all_in_string, '\n');
        if (current_pointer == NULL)
            break;
        counter++;
        all_in_string = current_pointer + 1;
    }

    return counter;
}

int my_fputs(const char* string, FILE* stream)
{
    assert(string != NULL);
    assert(stream != NULL);

    int counter = strlen(string);

    while (*string != '\n')
    {
        if (fputc(*string, stream) == EOF)
            return EOF;
        string++;
    }

    return counter;
}
