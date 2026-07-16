#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_LEN 250
#define MAX_FILENAME_LEN 250
#define SUCCESS 1
#define FAIL 0
#define FILE_IO_FAIL -1

char *formatFileName(const char *raw_filename);
int isFileEmpty(const char *filename);
int checkHeaderExists(const char *filename);
int getRecordCount (const char *filename);

#endif