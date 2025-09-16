#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "string_functions.h"
#include "io.h"
#include "work_with_pointers.h"


const int amount_of_lines = 5312;                   //так как длину строки определяем разностью соседних указателей
                                                    //FIXME поменять кодировку
int main()
{
    FILE* input_file = fopen("Onegin.txt", "r");
    if (input_file == NULL)
    {
        printf("Cannot open the file \"Onegin.txt\"\n");
        return -1;
    }


    int file_descriptor = fileno(input_file); //получили файловый дескриптор
    struct stat buf;
    fstat(file_descriptor, &buf);
    const long int amount_of_symbols = buf.st_size;

    // char strings[15][42] = {0};  //42 = 40 + '\n' + '\0'
    char* all_in_string = (char*) calloc(amount_of_symbols + 1, sizeof(char));     //неужели нужно в int всё хранить, чтобы EOF можно было прочитать?
    if (all_in_string == NULL)
    {
        printf("Cannot allocate memory\n");
        return -1;
    }
    all_in_string[amount_of_symbols] = '\0';

    size_t read_symbols = fread(all_in_string, sizeof(char), amount_of_symbols, input_file);
    // read_chars_from_file(amount_of_symbols, all_in_string, input_file);

    char** pointers_to_lines = (char**) calloc(amount_of_lines + 1, sizeof(char* )); //на 1 элемент больше, чтобы в конце массива всегда был нулевой указатель
    if (pointers_to_lines == NULL)
    {
        printf("Cannot allocate memory\n");
        return -1;
    }
    get_string_pointers(all_in_string, pointers_to_lines, read_symbols);

    // for (int index_ptr = 0; index_ptr <= amount_of_lines; index_ptr++) //
    //     printf("%x\n", pointers_to_lines[index_ptr]);


    // output_from_pointers(amount_of_lines, pointers_to_lines);

    // for (int k = 0; k < amount_of_symbols; k++)
    // printf("%c", all_in_string[k]);


    // for (int i = 0; i<= 14; i++)
    //    fgets(strings[i], 42, input_file);

    // char tmp[42] = {0};
    // strswap_govno(tmp, strings[0], strings[1]);
    // strswap_bykva(strings[0], strings[1]);


    // strswap_pachka(strings[0], strings[1]);

    // printf(strings[0]);
    // for (int j = 0; j <= 10; j++)
    //     printf("%c", strings[j]);
    printf("%lu\n", read_symbols);

    free(all_in_string);
    free(pointers_to_lines);
    fclose(input_file);
    return 0;
}
