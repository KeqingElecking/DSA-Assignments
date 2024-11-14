#include <stdio.h>

int main() {
    char filename[100];  // Array to store the filename

    // Ask the user for the filename
    printf("Enter the name of the file to create: ");
    scanf("%99s", filename);  // Read user input and limit input length to avoid buffer overflow

    // Open the file in "write" mode
    FILE *file = fopen(filename, "w");

    // Check if the file was created successfully
    if (file == NULL) {
        printf("Could not create file %s.\n", filename);
        return 1;
    }

    // Write text to the file
    fprintf(file, "This is a test file created by the user.\n");

    // Close the file
    fclose(file);

    printf("File '%s' created and written successfully.\n", filename);
    return 0;
}
