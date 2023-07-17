#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

// Structure to pass arguments to threads
typedef struct {
    int numbers[ARRAY_SIZE];
    int result;
} ThreadArgs;

// Function to calculate the sum of numbers
void* sumThread(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += args->numbers[i];
    }

    args->result = sum;
    pthread_exit(NULL);
}

// Function to calculate the product of numbers
void* productThread(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int product = 1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        product *= args->numbers[i];
    }

    args->result = product;
    pthread_exit(NULL);
}

int main() {
    int numbers[ARRAY_SIZE];
    ThreadArgs args;
    pthread_t tid1, tid2;

    printf("Enter 10 numbers: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    // Set the arguments for each thread
    for (int i = 0; i < ARRAY_SIZE; i++) {
        args.numbers[i] = numbers[i];
    }

    // Create Thread 1
    if (pthread_create(&tid1, NULL, sumThread, (void*)&args) != 0) {
        fprintf(stderr, "Error creating Thread 1.\n");
        return 1;
    }

    // Create Thread 2
    if (pthread_create(&tid2, NULL, productThread, (void*)&args) != 0) {
        fprintf(stderr, "Error creating Thread 2.\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Sum of numbers: %d\n", args.result);
    printf("Product of numbers: %d\n", args.result);

    return 0;
}
