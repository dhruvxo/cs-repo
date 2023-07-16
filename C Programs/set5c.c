#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char find_first_unique_char(char str[]) {
    int count[26] = {0}; // Array to store the count of each character (assuming lowercase letters)

    // Traverse the string and count the occurrences of each character
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    // Find the first character with count 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i] - 'a'] == 1) {
            return str[i];
        }
    }

    return '\0'; // If no unique character found
}

int main() {
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character if present

    char first_unique = find_first_unique_char(str);

    if (first_unique != '\0') {
        printf("The first unique character is %c\n", first_unique);
    } else {
        printf("There is no unique character in the string.\n");
    }

    return 0;
}
