#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

int front = -1, rear = -1;
int queue[maxsize];

void insert()
{
    int item;
    printf("\n Enter the element \n");
    scanf("\n%d",&item);
    if(rear == maxsize-1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if(front==-1&&rear=-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=item;
    printf("\nValue inserted");
}

void delete()
{
    int item;
    
}