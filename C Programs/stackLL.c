#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *top=NULL;

void push(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data=ele;
    if(top==NULL)
    {
        temp->next=NULL;
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        NODE *q=top;
        top=top->next;
        printf("\n%d\n",q->data);
        free(q);
    }
}
void display()
{
    NODE *q=top;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    while(q!=NULL)
    {
        printf("\n%d",q->data);
        q=q->next;
    }
}

int main()
{
    int ele,ch;
    printf("\n 1.Push\n 2.Pop\n 3.Display\n");
    scanf("%d",&ch);
    do{
        switch(ch)
        {
            case 1: printf("Enter the element to be pushed\n");
            scanf("%d",&ele);
            push(ele);
            break;
            
            case 2:pop();
            break;

            case 3:display();
            break;
        }
        printf("\n 1.Push\n 2.Pop\n 3.Display\n");
        scanf("%d",&ch);
    }while(ch<4);
    return 0;
}