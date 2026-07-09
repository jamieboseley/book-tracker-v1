#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 250
#define SUCCESS 1
#define FAIL 0
#define FILE_IO_FAIL -1

// Function prototypes.
//char *formatFileName(char *filename); // TO DO: Implement
int isFileEmpty(const char *filename);
int checkHeaderExists(const char *filename);
int getRecordCount (const char *filename);

#endif