#ifndef PROCESSING_FILES_H_
#define PROCESSING_FILES_H_

#include <stdio.h>
#include "io.h"

int ProcessingInputFile(FileInfo* ptr_file_info, char** argv);
FILE* ProcessingOutputFile(char** argv);


#endif // PROCESSING_FILES_H_
