#include <stdio.h>
// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}
// Function to perform quick sort on an array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    int treasure[100];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &treasure[i]);
    }
    quickSort(treasure, 0, n - 1);
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", treasure[i]);
    }
    printf("\n");
    printf("The adventurer is pleased with the sorted treasure and can now count their wealth.\n");
    return 0;
}