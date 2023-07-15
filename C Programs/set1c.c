#include <stdio.h>

void printFibonacciIterative(int n) {
    int first = 0;
    int second = 1;

    printf("%d %d ", first, second);

    for (int i = 3; i <= n; i++) {
        int next = first + second;
        printf("%d ", next);

        first = second;
        second = next;
    }
}

void printFibonacciRecursiveHelper(int n, int first, int second) {
    if (n <= 0)
        return;

    int next = first + second;
    printf("%d ", next);

    printFibonacciRecursiveHelper(n - 1, second, next);
}

void printFibonacciRecursive(int n) {
    if (n >= 1)
        printf("0 ");

    if (n >= 2)
        printf("1 ");

    printFibonacciRecursiveHelper(n - 2, 0, 1);
}

int main() {
    int n;
    scanf("%d", &n);

    printFibonacciIterative(n);
    printf("\n");
    printFibonacciRecursive(n);

    return 0;
}
