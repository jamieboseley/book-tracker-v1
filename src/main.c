#include "../include/linked_list.h"

int main (void)
{
    // Initialize variables.
    int choice;
    int record_count = 0;
    Node *head = NULL;
    char *filename = NULL;

    // Loop main menu.
    do
    {
        char buffer[MAX_BUFFER_LEN];
        int user_rec_count = 0;
        printf("\n===============Book Tracker V1===============\n");
        printf("1. Create New Records\n");
        printf("2. Display Records\n");
        printf("3. Delete Records\n");
        printf("4. Exit\n");
        printf("=============================================\n");
        
        printf("Enter choice (1-4): ");
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &choice) != 1)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch (choice)
        {
            // Create new records case.
            case 1:
                // Get filename from user.
                filename = getFilename();
                if (!filename) break;

                // Check if file with name already exists.
                if (checkFileExists(filename))
                {
                    printf("Error: \"%s\" already exists.\n", filename);
                    free(filename);
                    filename = NULL;
                    break;
                }

                // Check if the filename is a CSV.
                if (!isCSV(filename))
                {
                    printf("Error: \"%s\" is not a valid CSV filename.\n", filename);
                    free(filename);
                    filename = NULL;
                    break;
                }

                // Get the amount of records the user would like to enter.
                printf("Enter the number of records to be created: ");
                fgets(buffer, sizeof(buffer), stdin);
                if (sscanf(buffer, "%d", &user_rec_count) != 1)
                {
                    printf("Invalid number. Please try again.\n");
                    free(filename);
                    filename = NULL;
                    break;
                }
                printf("%d\n", user_rec_count);

                // Validate record count.
                if (user_rec_count <= 0)
                {
                    printf("Error: Record count must be above 0.\n");
                    free(filename);
                    filename = NULL;
                    break;
                }

                // TO DO: Finish create new records code.
                /// Loop for the amount of records the user would like to create.
                for (int i = 0; i < user_rec_count; i++)
                {
                    // Prompt user for the details of each book.
                    int id = i+1;
                    char *title;
                    char *author;
                    char *genre;
                    int page_count; // TO DO: Set invalid data to -1 in CSV? When display if = -1 display N/A in CL.
                    float price;
                    int rating;

                    printf("Enter the title for record #%d: ", id);
                    title = getString(MAX_TITLE_LEN);
                    if (!title) break;

                    printf("Enter the author for record #%d: ", id);
                    author = getString(MAX_AUTHOR_LEN);
                    if (!author) break;

                    printf("Enter the genre for record #%d: ", id);
                    genre = getString(MAX_AUTHOR_LEN);
                    if (!genre) break;

                    printf("Enter the page count for record #%d: ", id);
                    if (!getInt(&page_count)) break;

                    printf("Enter the price for record #%d: ", id);
                    if (!getPrice(&price)) break;

                    printf("Enter the rating (from 1 - 5) for record #%d: ", id);
                    if (!getInt(&rating)) break;

                    
                }

                break;

            // Display records case.
            case 2:
                // Get filename from user.
                filename = getFilename();
                if (!filename) break;

                // Import the list from a file.
                head = importFromCSV(filename, &record_count);
                if (!head)
                {  
                    printf("Error: There was a problem importing data.\n");
                    free(filename);
                    filename = NULL;
                    record_count = 0;
                    break;
                }

                // Display records.
                displayList(head);

                freeList(&head);
                free(filename);
                record_count = 0;
                filename = NULL;

                break;

            // Delete records case.
            case 3:
                // Get filename from user.
                filename = getFilename();
                if (!filename) break;

                // Attempt to delete the file.
                if (remove(filename) == 0)
                {
                    printf("%s was successfully deleted!\n", filename);
                }
                else
                {
                    printf("There was an error deleting the file.\n");
                }

                // Free filename.
                free(filename);
                filename = NULL;

                break;

            // Exit case.
            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
