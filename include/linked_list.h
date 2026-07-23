#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "book.h"

typedef struct Node {
    Book *data;
    struct Node *next;
} Node;

Node *createNode(int record_num, char *title, char *author, char *genre, int page_count, double price, int rating);
int insertNode(Node **head, int record_num, char *title, char *author, char *genre, int page_count, double price, int rating);
int countNodes(Node *head);
void freeList(Node **head); // TO DO: Refactor code to split free list and free node into separate functions? Could be useful for deleting single entries.

#endif