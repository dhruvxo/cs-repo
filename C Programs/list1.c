//Linked list with all opearations using switch case.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct llist
{
    NODE* head;
}LLIST;

//void initList(LLIST*);
NODE* getNode(int);
void insertFront(LLIST* , int);
void insertLast(LLIST* , int);
void insertAtPos(LLIST*, int, int);
void destroyList(LLIST*);
void display(LLIST*);
void deleteFront(LLIST*);
void deleteLast(LLIST*);
void deleteAtPos(LLIST*,int);
void search(LLIST*,int);

void initList(LLIST *sll)
{
    sll ->head = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->next=NULL;
    return temp;
}


void insertFront(LLIST *sll, int ele)
{
    NODE *temp = getNode(ele);
    temp->next = sll->head;
    sll->head = temp;
}

void insertLast(LLIST *sll, int ele)
{
    NODE *temp = getNode(ele);
    if(sll->head==NULL)
    {
        sll->head=temp;
        return;
    }
    NODE *p = sll->head;
    while(p->next!=NULL)
    p = p->next;
    p->next = temp;
}

int countnodes(LLIST *sll)
{
    int count = 0;
    if(sll->head = NULL)
    {
        return 0;
    }
    NODE *p = sll->head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void insertAtPos(LLIST *sll, int ele,int pos) 
{
    NODE *temp = getNode(ele);
    if(pos == 0)
    {
       temp->next = sll->head;
       sll->head = temp;
       return;
    }
    NODE *p=sll->head, *q=NULL;
    for(int i=0;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next = temp;
    temp->next = p;
}

void destroyList(LLIST *sll)
{
    NODE *p=sll->head, *q;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        free(q);        
    }
    sll->head = NULL;
}

void display(LLIST *sll)
{
    if(sll->head == NULL)
    {
        printf("\nThe List is empty.");
        return;
    }
    NODE *p = sll->head;
    while(p!=NULL)
    {
        printf("%3d",p->data);
        p = p->next;
    }
}

void deleteFront(LLIST *sll)
{
    if(sll->head==NULL)
    {
        printf("\nList is empty");
    }
    NODE *ptr = sll->head;
    sll->head = ptr->next;
    printf("\nDeleted element is %d", ptr->data);
    free(ptr);
}

void deleteLast(LLIST *sll)
{
    NODE *p=sll->head, *q;
    if(p->next==NULL)
    {
        sll->head = NULL;
        printf("Deleted element : %d",p->data);
        free(p);
    }
    
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next = NULL;
    printf("\nDeleted element is:%d",p->data);
    free(p);
}

void deleteAtPos(LLIST *sll, int pos)
{
    NODE *p = sll->head, *q = NULL;
    if(pos==0)
    {
        sll->head = p->next;
        printf("\nDeleted element is:%d",p->data);
        free(p);
        return;
    }

    for(int i=0;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next = p->next;
    printf("\nDeleted element is:%d",p->data);
    free(p);
}

void search(LLIST *sll, int ele)
{
   int count = 1;
   NODE *p = sll->head;
   if(sll->head==NULL)
   {
    printf("\nThe List is empty");
    exit(0);
   }
   else
   {
     while(p->data != ele && p->next!=NULL)
    {
        count++;
        p=p->next;
    }
    if(ele==p->data)
    printf("\nElement %d found at %d position", p->data,count);
    else
    printf("\nElement not found.");
   }
}

void reverse(LLIST *sll)
{
    NODE *p=NULL,*c,*n=NULL;
    c = sll->head;
    if(sll->head==NULL)
    {
        printf("\nThe list is empty.");
        exit(0);
    }
    else
    {
        while(c!=NULL)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        sll->head=p;
    }
}

void delAlter(LLIST *sll)
{
    NODE *p=NULL,*c=sll->head;
    while(c->next!=NULL)
    {
        p=c;
        c=c->next;
        p->next=c->next;
        free(c);
        c=p->next;
    }
}

int main()
{
    LLIST lobj;
    initList(&lobj);
    int choice,  pos, ele;
    do
    {
        printf("\n---------------------------------------------------\n");
        printf("\nEnter choice:");
        scanf("%d",&choice);
 
    switch(choice)
    {
        case 1:
        printf("\nEnter element:");
        scanf("%d",&ele);
        insertFront(&lobj,ele);
        break;

        case 2:
        printf("\nEnter element:");
        scanf("%d",&ele);
        insertLast(&lobj,ele);
        break;

        case 3:
        printf("\nEnter element:");
        scanf("%d",&ele);
        printf("\nEnter position:");
        scanf("%d",&pos);
        insertAtPos(&lobj,ele,pos);
        break;

        case 4:
        display(&lobj);
        break;

        case 5:
        deleteFront(&lobj);
        break;

        case 6:
        destroyList(&lobj);
        break;

        case 7:
        deleteLast(&lobj);
        break;

        case 8:
        printf("\nEnter position:");
        scanf("%d",&pos);
        deleteAtPos(&lobj,pos);
        break;

        case 9:
        printf("\nEnter element to search:");
        scanf("%d",&ele);
        search(&lobj,ele);
        break;

        case 10:
        reverse(&lobj);
        break;

        case 11:
        delAlter(&lobj);
        break;
    }
}
    while(choice);
}

//printf("Enter the element");
//scanf(ele);
//insertFront(&lobj,ele);
