#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "data.txt";
    const char *data = "0123456789\n";

    // Open the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Get the current size of the file
    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);

    // Check if the file size is greater than 20 bytes
    if (fileSize > 20) {
        // Open the file in append mode to write the data
        file = fopen(filename, "a");

        if (file == NULL) {
            printf("Error opening the file.\n");
            return 1;
        }

        // Write 10 bytes of data to the file
        fwrite(data, sizeof(char), 10, file);
        printf("Data written to the file.\n");

        // Close the file
        fclose(file);
    } else {
        printf("File size is not greater than 20 bytes. Data not written.\n");
        fclose(file);
    }

    return 0;
}
