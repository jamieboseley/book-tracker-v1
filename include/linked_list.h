#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "book.h"

typedef struct Node {
    Book *data;
    struct Node *next;
} Node;

Node *createNode(int record_num, char *title, char *author, char *genre, int page_count, double price, int rating);
int insertNode(Node **head, int record_num, char *title, char *author, char *genre, int page_count, double price, int rating);
// TO DO: Add insert, delete & free functions. Maybe a list length to count the nodes?

#endif