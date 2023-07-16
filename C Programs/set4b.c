#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bin2hex(char *bin) {
    int len = strlen(bin);
    int hex_len = (len + 3) / 4; // Calculate the length of the hexadecimal string
    char *hex = (char *)malloc((hex_len + 1) * sizeof(char));

    // Convert binary to hexadecimal
    for (int i = 0; i < hex_len; i++) {
        int value = 0;
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            if (index < len) {
                value = value * 2 + (bin[index] - '0');
            }
        }
        if (value <= 9) {
            hex[i] = value + '0';
        } else {
            hex[i] = value - 10 + 'A';
        }
    }

    hex[hex_len] = '\0'; // Null-terminate the hexadecimal string
    return hex;
}

int main() {
    char bin[100];
    scanf("%s", bin);

    char *hex = bin2hex(bin);
    printf("%s\n", hex);
    free(hex);

    return 0;
}
