#include <stdio.h>
#include <stdlib.h>
#include "string_functions.h"

int foo1(int);
int foo2(int);

int main()
{
/*
    fprintf(stdout, "  | foo1 | foo2 |\n"
                    " 1| %4d | %4d\n", foo1(1), foo2(1));
    fprintf(stdout, " 2| %4d | %4d\n", foo1(1), foo2(1));

    // return EXIT_SUCCESS;
*/
    char strings[15][42] = {0};  //42 = 40 + '\n' + '\0'

    FILE* fp = fopen("Onegin_test.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open the file \"Onegin_test.txt\"\n");
        return -1;
    }

    for (int i = 0; i<= 14; i++)
        fgets(strings[i], 42, fp);

    /*
    char tmp[42] = {0};
    strswap_govno(tmp, strings[0], strings[1]);
    strswap_bykva(strings[0], strings[1]);
    */

    strswap_pachka(strings[0], strings[1]);

    // printf(strings[0]);
    for (int j = 0; j <= 14; j++)
        printf("%s", strings[j]);

    fclose(fp);
    return 0;
}


/*
int foo1(int i) {
    int a = 0;
    a += i;
    return a;
}

int foo2(int i) {
    static int a = 0; //статик переменная инициализируется один раз!
    a += i;
    return a;
}

int a

int* a
const int* a
int* const a
int const* a

const int* a (int)

const int* (*a) (int) //указатель на функцию
*/
