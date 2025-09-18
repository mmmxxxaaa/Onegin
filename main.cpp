#include <stdio.h>
#include <stdlib.h>

#include "string_functions.h"
#include "io.h"
#include "sorting.h"
#include "processing_files.h"

#include "string.h"

int main(int argc, char** argv)
{
    FileInfo file_info = {0};                                                       //FIXME разобраться с варнингами через функцию, принимающая знаковый тип, которая проверяет >= 0 и приводит его к беззнаковому типу
//------------
    ConstructFileInfo(&file_info, argv);
//-----------
    FILE* output_file = ProcessingOutputFile(argv);

    BubbleSort(file_info.pointers_to_lines, file_info.amount_of_lines, MyStrcmp);
    OutputFromPointers(output_file, file_info.amount_of_lines, file_info.pointers_to_lines);

    qsort(file_info.pointers_to_lines, file_info.amount_of_lines, sizeof(StringInfo), MyStrcmpReversed);
    OutputFromPointers(output_file, file_info.amount_of_lines, file_info.pointers_to_lines);

    fprintf(output_file, "%s\n", file_info.text_buffer);

    FreeStructFileInfo(&file_info);
    return 0;
}



