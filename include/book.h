#ifndef BOOK_H
#define BOOK_H

#include "fileio.h"

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 30
#define MAX_GENRE_LEN 20

typedef struct {
    int record_num;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    int page_count;
    double price;
    int rating; // The user's rating out of 5.
} Book;

#endif