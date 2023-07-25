#include <stdio.h>
#include <string.h>

void excel_column_title(int column_number) {
    char column_title[100];
    int index = 0;

    while (column_number > 0) {
        int rem = (column_number - 1) % 26;
        column_title[index++] = 'A' + rem;
        column_number = (column_number - 1) / 26;
    }

    column_title[index] = '\0';
    strrev(column_title);  // Reverse the string to get the correct column title

    printf("%s", column_title);
}

int main() {
    int column_number;
    scanf("%d", &column_number);

    excel_column_title(column_number);

    return 0;
}