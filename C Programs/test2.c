#include <stdio.h>
#include <pthread.h>

#define NUMCOUNT 10

int numbers[NUMCOUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = 0;
int product = 1;

void* sum_thread(void* arg) {
    for (int i = 0; i < NUMCOUNT; i++) {
        sum += numbers[i];
    }
    pthread_exit(NULL);
}

void* product_thread(void* arg) {
    for (int i = 0; i < NUMCOUNT; i++) {
        product *= numbers[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, sum_thread, NULL);
    pthread_create(&thread2, NULL, product_thread, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("Sum of numbers: %d\n", sum);
    printf("Product of numbers: %d\n", product);
    
    return 0;
}