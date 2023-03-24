#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap {
    int size;
    int* array;
} MinHeap;

void create(MinHeap* heap) {
    int n = heap->size;
    int i, j, k, temp;
   
    for (i = n/2; i >= 1; i--) {
        k = i;
        j = 2*k;
        temp = heap->array[k];
       
        while (j <= n) {
            if (j < n && heap->array[j] > heap->array[j+1]) {
                j++;
            }
            heap->array[k] = heap->array[j];
            k = j;
            j = 2*k;
        }
        heap->array[k] = temp;
    }
}

void display(MinHeap* heap) {
    int i;
    for (i = 1; i <= heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
}

int main() {
    int i, n;
    scanf("%d", &n);
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->size = n;
    heap->array = (int*) malloc((n+1) * sizeof(int));
    for (i = 1; i <= n; i++) {
        scanf("%d", &heap->array[i]);
    }
    create(heap);
    display(heap);
    free(heap->array);
    free(heap);
    return 0;
}