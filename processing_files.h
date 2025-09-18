#ifndef PROCESSING_FILES_H_
#define PROCESSING_FILES_H_

#include <stdio.h>
#include "io.h"
#include "errors_codes.h"

ErrorsCodes ProcessingInputFile(FileInfo* ptr_file_info, char** argv);
FILE* ProcessingOutputFile(char** argv);
ErrorsCodes ConstructFileInfo(FileInfo* ptr_file_info, char** argv);


#endif // PROCESSING_FILES_H_
