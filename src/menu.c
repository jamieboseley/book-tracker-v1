#include "../include/menu.h"



/**
 * [menu.c]
 * Function: *getFilename
 * Purpose: Gets a raw filename from a user and formats it.
 * Parameters:
 *   - None.
 * Example: filename = getFilename;
 * Effects: Writes to console.
 * Return: NULL if an error occured. The char pointer if successful.
*/
char *getFilename()
{
    char raw_filename[MAX_FILENAME_LEN];
    char *filename;

    printf("Enter the filename: ");

    // Failure reading filename.
    if (!fgets(raw_filename, sizeof(raw_filename), stdin))
    {
        printf("Error: Failed to read filename.\n");
        return NULL;
    }

    // Remove newline from raw filename.
    raw_filename[strcspn(raw_filename, "\n")] = '\0';

    // No filename was entered.
    if (raw_filename[0] == '\0')
    {
        printf("Error: No filename was entered.\n");
        return NULL;
    }

    // Format filename.
    filename = formatFileName(raw_filename);
    if (!filename)
    {
        printf("Error: There was a problem formatting the filename.\n");
        return NULL;
    }

    return filename;
}