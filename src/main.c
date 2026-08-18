#include "../include/linked_list.h"

int main (void)
{
    // Initialize variables.
    int choice;
    char buffer[MAX_BUFFER_LEN];

    // Loop main menu.
    do
    {
        printf("\n===============Book Tracker V1===============\n");
        printf("1. Create New Records\n");
        printf("2. Edit Records\n");
        printf("3. Display Records\n");
        printf("4. Delete Records\n");
        printf("5. Exit\n");
        printf("=============================================\n");
        
        printf("Enter choice (1-5): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);

        switch (choice)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/*
import
export
Display
new list

*/