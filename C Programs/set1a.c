#include <stdio.h>

void combineStudents(int a[], int n) {
    int i = n - 1;  // Index for array a
    int j = 2 * n - 1;  // Index for merged array

    while (i >= 0 && j >= n) {
        if (a[i] >= a[j]) {
            a[j] = a[i];
            i--;
        } else {
            a[j] = a[j];
        }
        j--;
    }
}

int main() {
    int n;
    int a[200];  // Adjusted array size to accommodate both rows

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);  // Reusing the same variable to get the size of the second row
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i + n]);
    }

    combineStudents(a, n);

    for (int i = 0; i < n * 2; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
