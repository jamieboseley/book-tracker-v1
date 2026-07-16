#include "../include/linked_list.h"



/**
 * [linked_list.c]
 * Function: *createNode
 * Purpose: Creates a new dynamically allocated node.
 * Parameters:
 *   - record_num (int): The record number.
 *   - title (char): The book title.
 *   - author (char): The book author.
 *   - genre (char): The book genre.
 *   - page_count (int): The book page count.
 *   - price (double): The book price.
 *   - rating (int): The book rating.
 * Example: Node *head = createNode(1, "harry potter", "jk rowling", "fantasy", 494, 19.99, 5);
 * Effects: Allocates memory on the heap.
 * Return: NULL if an error occured. The node pointer if successful.
*/
Node *createNode(int record_num, char *title, char *author, char *genre, int page_count, double price, int rating)
{
    // Allocate memory for the head.
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return NULL;

    // Set the pointers and data.
    newNode->next = NULL;

    newNode->data->record_num = record_num;
    newNode->data->page_count = page_count;
    newNode->data->price = price;
    newNode->data->rating = rating;

    strncpy(newNode->data->title, title, MAX_TITLE_LEN);
    strncpy(newNode->data->author, author, MAX_AUTHOR_LEN);
    strncpy(newNode->data->genre, genre, MAX_GENRE_LEN);

    return newNode;
}