#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

struct dequeue
{
    struct node *front;
    struct node *rear;
};
struct node
{
    int data;
    struct node *prev,*next;
};
struct dequeue *dq;
void initdeque(struct dequeue *dq)
{
dq->front = dq->rear = NULL;
}

void qinsert_head(int x,struct dequeue *dq)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=temp->next=NULL;

    if(dq->front=NULL) //first element
    dq->front=dq->rear=temp;
    else
    {
        temp->next=dq->front; //insert in front
        dq->front->prev=temp;
        temp->prev=NULL;
        dq->front=temp;
    }
}

// void main()
// {
//     int choice;
//     while (1) {

//         printf("\n\t1. To insert list\n");

//         printf("\nEnter Choice :\n");
//         scanf("%d", &choice);

//         switch (choice) {
//         case 1:
//             insert();
//             break;
//             case 2:
//         default:
//             printf("Incorrect Choice\n");
//         }
//     }
//     return;
// }