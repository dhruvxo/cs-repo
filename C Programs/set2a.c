#include <stdio.h>

void search(int arr[], int n, int target) {
    int first = -1, last = -1;
    int low = 0, high = n - 1;

    // Find the first occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;  // Continue searching in the left half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    low = 0;
    high = n - 1;

    // Find the last occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;  // Continue searching in the right half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d %d", first, last);
}

int main() {
    int arr[20];
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    search(arr, n, k);
    return 0;
}
