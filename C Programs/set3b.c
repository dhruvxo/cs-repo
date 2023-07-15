#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine) {
    int ransomNoteCount[26] = {0};   // Array to count characters in the ransom note
    int magazineCount[26] = {0};     // Array to count characters in the magazine

    // Count characters in the ransom note
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        ransomNoteCount[ransomNote[i] - 'a']++;
    }

    // Count characters in the magazine
    for (int i = 0; magazine[i] != '\0'; i++) {
        magazineCount[magazine[i] - 'a']++;
    }

    // Compare the counts
    for (int i = 0; i < 26; i++) {
        if (ransomNoteCount[i] > magazineCount[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char ransomNote[20], magazine[20];
    scanf("%s", ransomNote);
    scanf("%s", magazine);

    bool result;
    result = canConstruct(ransomNote, magazine);

    if (result == true) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}
