#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

void printSpiral(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Print rightmost column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Print leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printSpiral(matrix, rows, cols);

    return 0;
}
