#include <stdio.h>
#include <stdlib.h>

#define SIZE 13
#define PRIME 7

void insertIntoHash(int key, int *hashtable)
{
    int index = key % SIZE;
    int step = PRIME - (key % PRIME);
    int i = 1;

    while (hashtable[index] != 0) {
        index = (index + i * step) % SIZE;
        i++;
        if (i == SIZE) {
            printf("Error: Hash table is full\n");
            exit(1);
        }
    }

    hashtable[index] = key;
}

void printHashTable(int *hashtable)
{
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", hashtable[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int stk[n];
    for (int k = 0; k < n; k++) {
        scanf("%d", &stk[k]);
    }

    int h[SIZE] = {0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == SIZE) {
            printf("-1\n");
            break;
        }
        if (stk[i] < 0) {
            continue;
        }
        insertIntoHash(stk[i], h);
        count++;
    }

    printHashTable(h);

    return 0;
}
