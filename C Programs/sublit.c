#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int size;
    int* array;
} Heap;

void create(Heap* heap) {
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
            if (temp <= heap->array[j]) {
                break;
            }
            heap->array[k] = heap->array[j];
            k = j;
            j = 2*k;
        }
        heap->array[k] = temp;
    }
}

void display(Heap* heap) {
    int i;
    for (i = 1; i <= heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
}

int main() {
    int i, n;
    scanf("%d", &n);
    Heap* heap = (Heap*) malloc(sizeof(Heap));
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