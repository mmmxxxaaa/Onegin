#include <stdio.h>
#include <stdlib.h>

#include "string_functions.h"
#include "io.h"
#include "work_with_pointers.h"

const long int amount_of_symbols = 182127;          //все равно на отсутствие \0 в конце
const int amount_of_lines = 5312;                   //так как длину строки определяем разностью соседних указателей
                                                    //FIXME поменять кодировку
int main()
{
    FILE* fp = fopen("Onegin.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open the file \"Onegin_test.txt\"\n");
        return -1;
    }

    // char strings[15][42] = {0};  //42 = 40 + '\n' + '\0'
    char all_in_string[amount_of_symbols] = {};     //неужели нужно в int всё хранить, чтобы EOF можно было прочитать?

    read_chars_from_file(amount_of_symbols, all_in_string, fp);

    char* pointers_to_lines[amount_of_lines] = {NULL};
    get_string_pointers(all_in_string, pointers_to_lines, amount_of_symbols);

    output_from_pointers(amount_of_lines, pointers_to_lines);



    // for (int k = 0; k < amount_of_symbols; k++)
    // printf("%c", all_in_string[k]);


    // for (int i = 0; i<= 14; i++)
    //    fgets(strings[i], 42, fp);

    // char tmp[42] = {0};
    // strswap_govno(tmp, strings[0], strings[1]);
    // strswap_bykva(strings[0], strings[1]);


    // strswap_pachka(strings[0], strings[1]);

    // printf(strings[0]);
    // for (int j = 0; j <= 10; j++)
    //     printf("%c", strings[j]);

    fclose(fp);
    return 0;
}
