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

    // Allocate memory for the data.
    newNode->data = malloc(sizeof(Book));
    if (!newNode->data)
    {
        free(newNode);
        return NULL;
    }

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



/**
 * [linked_list.c]
 * Function: insertNode
 * Purpose: Inserts a dynamically allocated node to a linked list.
 * Parameters:
 *   - head (Node): A double pointer to the head node.
 *   - record_num (int): The record number.
 *   - title (char): The book title.
 *   - author (char): The book author.
 *   - genre (char): The book genre.
 *   - page_count (int): The book page count.
 *   - price (double): The book price.
 *   - rating (int): The book rating.
 * Example: if (!insertNode(&head, 1, "harry potter", "jk rowling", "fantasy", 494, 19.99, 5)) break;
 * Effects: Allocates memory on the heap.
 * Return: FAIL if an error occured. SUCCESS if successful.
*/
int insertNode(Node **head, int record_num, char *title, char *author, char *genre, int page_count, double price, int rating)
{
    // Create the new node.
    Node *newNode = createNode(record_num, title, author, genre, page_count, price, rating);
    if (!newNode) return FAIL;

    // If the linked list is empty, set the head to the new node.
    if (!*head)
    {
        *head = newNode;
        return SUCCESS;
    }

    // If the linked list is not empty, set the last node the new node.
    Node *currentNode = *head;
    while (currentNode->next)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return SUCCESS;
}



/**
 * [linked_list.c]
 * Function: countNodes
 * Purpose: Counts the total number of nodes in a linked list.
 * Parameters:
 *   - head (Node): A pointer to the head node.
 * Example: int count = countNodes(head);
 * Effects: None.
 * Return: The total number of nodes in a linked list.
*/
int countNodes(Node *head)
{
    // If the linked list is empty, return 0.
    if (!head) return 0;

    // Traverse the linked list and count the nodes.
    int count = 0;
    Node *currentNode = head;

    while (currentNode)
    {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}



/**
 * [linked_list.c]
 * Function: freeList
 * Purpose: Frees all the nodes and data in a linked list.
 * Parameters:
 *   - head (Node): A double pointer to the head node.
 * Example: freeList(&head);
 * Effects: Frees memory on the heap.
 * Return: None.
*/
void freeList(Node **head)
{
    // Set the current node.
    Node *currentNode = *head;
    Node *nextNode;

    // Iterate through the list to free nodes & data.
    while (!currentNode)
    {
        nextNode = currentNode->next;
        free(currentNode->data);
        free(currentNode);
        currentNode = nextNode;
    }

    *head = NULL;
} // TO DO: Should this have a return value to signify success?