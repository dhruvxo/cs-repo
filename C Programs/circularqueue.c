#include <stdio.h>
#define max 3
int queue[max]; //array declaration
int front=-1;
int rear=-1;
// function to insert an element in a circular queue
void enqueue(int element)
{
    if(front==-1 && rear==-1) //condition to check if queue is empty
    {
        front=0;
        rear=0;
        queue[rear]=element;
    }
    else if ((rear+1)%max==front) //condition to check if queue is full
    {
        printf("Queue is overflow");
    }
    else
    {
        rear=(rear+1)%max; //rear is incrememnted
        queue[rear]=element; //assiging a value to the queue at the..
    }
}

//function to delete the element from the queue
void dequeue()
{
    if (front == -1 && (rear=-1)) //to check if queue is empty
    {
        printf("\nUNDERFLOW\n");
    }
    else if(front==rear)
    {
        printf("\nThe dequeued element is %d",queue[front]);
            front=-1;
            rear=-1;
        }
        else
        {
            printf("\nThe dequeued element is %d", queue[front]);
            front=(front+1)%max;
        }
}