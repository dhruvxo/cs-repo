#include <stdio.h>

void rotateMatrix(int mat[10][10], int N) {
    // Transpose the matrix
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Reverse each row
    for (int i = 0; i < N; i++) {
        int left = 0;
        int right = N - 1;
        while (left < right) {
            int temp = mat[i][left];
            mat[i][left] = mat[i][right];
            mat[i][right] = temp;
            left++;
            right--;
        }
    }
}

void printMatrix(int mat[10][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    int mat[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    rotateMatrix(mat, N);
    printMatrix(mat, N);

    return 0;
}