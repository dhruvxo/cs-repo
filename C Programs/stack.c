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

int isFull(STACK *ps)
{
    return ps->top==MAX-1 //if it returns 0, stack isnt full
}

int isEmpty(STACK *ps)
{
    return ps->top==-1 //if it returns 0, stack isnt empty
}

int push(STACK *ps, int ele)
{
    if(isFull(ps))
    printf("Stack Overflow!");
    return 0;
    ps->top++;
    ps->s[ps->top]=ele;
    //ps->s[++ps->top]
    return 1;
}

int pop(STACK *ps, int *pe) //*pe is used to store the element which gets popped
{
    if(isEmpty(ps))
    {
        printf("Stack Underflow! (No elements)");
        return 0;
    }
    *pe=ps->s[ps->top];
    ps->s[ps->top--];
    //*pe=ps->s[ps->top--];
    return 1;
}

int peek(STACK *ps, int *pe)
{
     if(isEmpty(ps))
    {
        //printf("Stack Underflow! (No elements)");
        return 0;
    }
    *pe=ps->s[ps->top];
    return 1;
}

void display(STACK *ps)
{
    if(isEmpty(ps))
    {
        printf("Stack Underflow!")
    }
    for(int i=ps->top;i>-1;i--)
    {
        printf("%d",ps->s[i]);
    }
}