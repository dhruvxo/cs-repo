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
    if(front==-1 && rear=-1)
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
    if (front == -1 || front>rear)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
         item=queue[front];
        if(front == rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front = front+1;
            return;
        }
    }
}

void main()
{
    int choice;
    while (1) {

        printf("\n\t1. To insert list\n1. To delete list\n");

        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
            case 2:
            delete();
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return;
}