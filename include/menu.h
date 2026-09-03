#ifndef MENU_H
#define MENU_H

#include "fileio.h"

char *getFilename();
char *getString(int max_length);
int getInt(int *num);
int getPrice(float *price);

#endif