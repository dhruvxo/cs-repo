#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void invertVowels(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (isVowel(s[left]) && isVowel(s[right])) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        } else if (isVowel(s[left])) {
            right--;
        } else {
            left++;
        }
    }
}

int main() {
    char s[100000];
    scanf("%s", s);

    invertVowels(s);

    printf("%s", s);
    return 0;
}
