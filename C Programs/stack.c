#include<stdio.h>
#define MAX 10

typedef struct stack{
    int top;
    int s[MAX];
}STACK;

void initStack(STACK *ps) //*ps is pointer to the typedef structure
{
ps->top=-1;
}