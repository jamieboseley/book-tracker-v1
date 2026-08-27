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
        printf("\n===============Book Tracker V1===============\n");
        printf("1. Create New Records\n");
        printf("2. Edit Records\n");
        printf("3. Display Records\n");
        printf("4. Delete Records\n");
        printf("5. Exit\n");
        printf("=============================================\n");
        
        printf("Enter choice (1-5): ");
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
                break;

            // Edit records case.
            case 2:
                break;

            // Display records case.
            case 3:
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
            case 4:
                break;

            // Exit case.
            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
