#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColours(int a[], int arr_size) {
    int low = 0;       // Index for the region of red
    int mid = 0;       // Index for the region of white
    int high = arr_size - 1;   // Index for the region of blue

    while (mid <= high) {
        if (a[mid] == 0) {     // If the current element is red
            swap(&a[low], &a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {  // If the current element is white
            mid++;
        } else {                  // If the current element is blue
            swap(&a[mid], &a[high]);
            high--;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortColours(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
