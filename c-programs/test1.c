#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int numbers[10];
    int even_sum = 0, odd_sum = 0;
    int i;

    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        for (i = 0; i < 10; i++) {
            if (numbers[i] % 2 == 0) {
                even_sum += numbers[i];
            }
        }
        printf("Sum of even numbers: %d\n", even_sum);
    } else {
        // Parent process
        for (i = 0; i < 10; i++) {
            if (numbers[i] % 2 != 0) {
                odd_sum += numbers[i];
            }
        }
        printf("Sum of odd numbers: %d\n", odd_sum);
    }

    return 0;
}