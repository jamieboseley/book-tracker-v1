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
    while (currentNode)
    {
        nextNode = currentNode->next;
        free(currentNode->data);
        free(currentNode);
        currentNode = nextNode;
    }

    *head = NULL;
} // TO DO: Should this have a return value to signify success?



/**
 * [linked_list.c]
 * Function: importFromCSV
 * Purpose: Reads a formatted CSV file and creates a linked list using the data.
 * Parameters:
 *   - filename (char): The name of the file.
 *   - record_count (int): A pointer to the record count.
 * Example: Node *head = importFromCSV("data.csv", &record_count);
 * Effects: Opens a file in read only mode & allocates memory on the heap.
 * Return: A pointer to the head node. NULL if an error occured.
*/
Node *importFromCSV(const char *filename, int *record_count) // TO DO: Add checkHeaderExists implementation.
{
    // Attempt to open the file.
    FILE *fh = fopen(filename, "r");
    if (!fh) return NULL;

    // Get record count.
    *record_count = getRecordCount(filename);
    if (*record_count <= 0)
    {
         fclose(fh);
         return NULL;
    }

    // Check header exists and skip it.
    char buffer[MAX_BUFFER_LEN];
    if (!fgets(buffer, MAX_BUFFER_LEN, fh))
    {
        fclose(fh);
        return NULL;
    }
    
    // Read the data into a linked list using tokens.
    Node *head = NULL;
    while (fgets(buffer, MAX_BUFFER_LEN, fh))
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        char *token = strtok(buffer, ",");
        if (!token) continue;
        int record_num = atoi(token);

        char *title = strtok(NULL, ",");
        if (!title) title = "";

        char *author = strtok(NULL, ",");
        if (!author) author = "";

        char *genre = strtok(NULL, ",");
        if (!genre) genre = "";

        token = strtok(NULL, ",");
        int page_count = token ? atoi(token) : 0;

        token = strtok(NULL, ",");
        double price = token ? atof(token) : 0.0;

        token = strtok(NULL, ",");
        int rating = token ? atoi(token) : 0;

        if (!insertNode(&head, record_num, title, author, genre, page_count, price, rating))
        {
            // TO DO: Add fail code. Free data?
            fclose(fh);
            return NULL;
        }
    }

    fclose(fh);
    return head;
}



/**
 * [linked_list.c]
 * Function: exportToCSV
 * Purpose: Prints all contents of a linked list to a formatted CSV file.
 * Parameters:
 *   - head (Node): A pointer to the head node.
 *   - filename (char): The name for the file.
 * Example: if (exportToCSV(head, "data.csv")) printf("Success\n");
 * Effects: Opens and writes to a file under filename.
 * Return: SUCCESS if the data was written. FAIL or FILE_IO_FAIL if the data was not written.
*/
int exportToCSV(Node *head, const char *filename)
{
    // Check to see if the list is empty. Check to see if a file with the same name already exists.
    if (!head || checkFileExists(filename)) return FAIL;

    // Attempt to open the file.
    FILE *fh = fopen(filename, "w");
    if (!fh) return FILE_IO_FAIL;

    // Print the header.
    fprintf(fh, "ID,Title,Author,Genre,PageCount,Price,Rating\n");

    // Set the current node.
    Node *currentNode = head;
    

    // Iterate through the linked list and print the contents.
    while (currentNode)
    {
        fprintf(fh, "%d,%s,%s,%s,%d,%.2lf,%d", currentNode->data->record_num, currentNode->data->title, currentNode->data->author, currentNode->data->genre, currentNode->data->page_count, currentNode->data->price, currentNode->data->rating);

        if (currentNode->next) fprintf(fh, "\n");

        currentNode = currentNode->next;
    }

    fclose(fh);
    return SUCCESS;
}



/**
 * [linked_list.c]
 * Function: displayList
 * Purpose: Prints all contents of a linked list to the console in an aligned format.
 * Parameters:
 *   - head (Node): A pointer to the head node.
 * Example: displayList(head);
 * Effects: None.
 * Return: None.
*/
void displayList(Node *head)
{
    // Check to see if the list is empty.
    if (!head)
    {
        printf("No records to display.");
        return;
    }

    // Define the headers.
    const char *h1 = "ID";
    const char *h2 = "Title";
    const char *h3 = "Author";
    const char *h4 = "Genre";
    const char *h5 = "PageCount";
    const char *h6 = "Price";
    const char *h7 = "Rating";

    // Initialize the max length for each column and the universial spacing gap.;
    int max_col1_len = strlen(h1);
    int max_col2_len = strlen(h2);
    int max_col3_len = strlen(h3);
    int max_col4_len = strlen(h4);
    int max_col5_len = strlen(h5);
    int max_col6_len = strlen(h6);
    int max_col7_len = strlen(h7);
    int column_width = 5;

    Node *currentNode = head;

    // Iterate through each record and record the longest length of each column.
    while (currentNode)
    {
        int record_num_len = snprintf(NULL, 0, "%d", currentNode->data->record_num);
        max_col1_len = ((record_num_len > max_col1_len) ? record_num_len : max_col1_len);

        int title_len = strlen(currentNode->data->title);
        max_col2_len = ((title_len > max_col2_len) ? title_len : max_col2_len);

        int author_len = strlen(currentNode->data->author);
        max_col3_len = ((author_len > max_col3_len) ? author_len : max_col3_len);

        int genre_len = strlen(currentNode->data->genre);
        max_col4_len = ((genre_len > max_col4_len) ? genre_len : max_col4_len);

        int page_count_len = snprintf(NULL, 0, "%d", currentNode->data->page_count);
        max_col5_len = ((page_count_len > max_col5_len) ? page_count_len : max_col5_len);

        int price_len = snprintf(NULL, 0, "%lf", currentNode->data->price);
        max_col6_len = ((price_len > max_col6_len) ? price_len : max_col6_len);

        int rating_len = snprintf(NULL, 0, "%d", currentNode->data->rating);
        max_col7_len = ((rating_len > max_col7_len) ? rating_len : max_col7_len);

        currentNode = currentNode->next;
    }

    // Add the column width.
    max_col1_len += column_width;
    max_col2_len += column_width;
    max_col3_len += column_width;
    max_col4_len += column_width;
    max_col5_len += column_width;
    max_col6_len += column_width;
    max_col7_len += column_width;

    // Print the header with the spacing.
    printf("%-*s%-*s%-*s%-*s%*s%*s%*s\n", max_col1_len, h1, max_col2_len, h2, max_col3_len, h3, max_col4_len, h4, max_col5_len, h5, max_col6_len, h6, max_col7_len, h7);
    
    // Print the data with the spacing.
    currentNode = head;
    while (currentNode)
    {
        char price_str[32];
        snprintf(price_str, sizeof(price_str), "$%.2lf", currentNode->data->price);
        printf("%-*d%-*s%-*s%-*s%*d%*s%*d\n", max_col1_len, currentNode->data->record_num, max_col2_len, currentNode->data->title, max_col3_len, currentNode->data->author, max_col4_len, currentNode->data->genre, max_col5_len, currentNode->data->page_count, max_col6_len, price_str, max_col7_len, currentNode->data->rating);
        currentNode = currentNode->next;
    }
}