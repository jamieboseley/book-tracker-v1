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



/**
 * [menu.c]
 * Function: *getString
 * Purpose: Gets a string from the user, cleans it up, and returns it
 * Parameters:
 *   - max_length (int): The max length for the string.
 * Example: char *str = getString(100);
 * Effects: None.
 * Return: NULL if an error occured. The char pointer if successful.
*/
char *getString(int max_length)
{
    char *str = malloc(max_length);

    // Failure allocating memory.
    if (!str) return NULL;

    // Failure reading string.
    if (!fgets(str, max_length, stdin)) 
    {
        free(str);
        return NULL;
    }

    // Remove newline from string.
    str[strcspn(str, "\n")] = '\0';

    // No string was entered.
    if (str[0] == '\0') 
    {
        free(str);
        return NULL;
    }

    return str;
}



/**
 * [menu.c]
 * Function: getInt
 * Purpose: Gets an int from the user.
 * Parameters:
 *   - *num (int): A pointer to an integer value.
 * Example: if (!getInt(&rating)) break;
 * Effects: Updates pointer.
 * Return: SUCCESS if successful. FAIL if an error occured.
*/
int getInt(int *num)
{
    char buffer[MAX_BUFFER_LEN];

    // Read into buffer.
    if (!fgets(buffer, sizeof(buffer), stdin)) return FAIL;

    // Scan buffer for int.
    if (sscanf(buffer, "%d", num) != 1)
    {
        return FAIL;
    }

    return SUCCESS;
}



/**
 * [menu.c]
 * Function: getPrice
 * Purpose: Gets a price from the user.
 * Parameters:
 *   - *price (float): A pointer to an double value.
 * Example: if (!getPrice(&price)) break;
 * Effects: Updates pointer.
 * Return: SUCCESS if successful. FAIL if an error occured.
*/
int getPrice(double *price)
{
    char buffer[MAX_BUFFER_LEN];

    // Read into buffer.
    if (!fgets(buffer, sizeof(buffer), stdin)) return FAIL;

    // Scan buffer for int.
    if (sscanf(buffer, "%lf", price) != 1)
    {
        return FAIL;
    }

    return SUCCESS;
}