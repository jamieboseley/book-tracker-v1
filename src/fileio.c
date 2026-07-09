#include "../include/fileio.h"



/**
 * [fileio.c]
 * Function: isFileEmpty
 * Purpose: Checks to see if a file is empty by taking the position in bytes at the end of the file.
 * Parameters:
 *   - filename (char): The name of the file being opened.
 * Example: if (isFileEmpty("data.csv")) printf("Empty\n");
 * Effects: Opens & reads the file under filename.
 * Return: SUCCESS if file is empty. FAIL if file is not empty. FILE_IO_FAIL if the file could not be opened.
*/
int isFileEmpty(const char *filename)
{
    // Attempt to open the file.
    FILE *fh = fopen(filename, "r");
    if (!fh) return FILE_IO_FAIL;

    // Move pointer to the end of the file and get it's position.
    fseek(fh, 0, SEEK_END);
    long position = ftell(fh);

    fclose(fh);

    // Check if file is empty.
    if (position <= 0) return SUCCESS;

    return FAIL;
}



/**
 * [fileio.c]
 * Function: checkHeaderExists
 * Purpose: Checks to see if a header exists within a file.
 * Parameters:
 *   - filename (char): The name of the file being opened.
 * Example: if (!checkHeaderExists("data.csv")) return;
 * Effects: Opens & reads the file under filename.
 * Return: SUCCESS if the header exists. FAIL if header does not exist. FILE_IO_FAIL if the file could not be opened.
*/
int checkHeaderExists(const char *filename)
{
    // Attempt to open the file.
    FILE *fh = fopen(filename, "r");
    if (!fh) return FILE_IO_FAIL;

    // Check if file is empty.
    if (isFileEmpty(filename)) return FAIL;

    char *header = "Title,Author,Genre,PageCount,Price,Rating";
    int header_len = strlen(header);

    // Reads the first line into the buffer.
    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, fh);

    fclose(fh);

    // Compares lengths of the buffer and header.
    if (strlen(buffer) == header_len)
    {
        // Compare buffer to the expected header formatting.
        if(strncmp(header, buffer, header_len) == 0) return SUCCESS;
    }

    return FAIL;
}



/**
 * [fileio.c]
 * Function: getRecordCount
 * Purpose: Opens a file and counts the number of entries.
 * Parameters:
 *   - filename (char): The name of the file being opened.
 * Example: int count = getRecordCount("data.csv");
 * Effects: Opens & reads the file under filename.
 * Return: record_count containing the number of entries. FILE_IO_FAIL if the file could not be opened.
*/
int getRecordCount (const char *filename)
{
    // Attempt to open the file.
    FILE *fh = fopen(filename, "r");
    if (!fh) return FILE_IO_FAIL;

    char buffer[MAX_BUFFER_SIZE];
    int record_count;

    // Read and discard the header.
    fgets(buffer, MAX_BUFFER_SIZE, fh); // TO DO: Check header exists.

    while (fgets(buffer, MAX_BUFFER_SIZE, fh)) record_count++;

    // Close file & return the record count.
    fclose(fh);
    return record_count;
}