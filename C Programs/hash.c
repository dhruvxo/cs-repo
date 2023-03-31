#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 7

typedef struct node
{
    int rno;
    char name[30];
    struct node *next;
}NODE;

void initTable(NODE *ht[size])
{
    for(int i=0;i<size;i++)
    ht[i]=NULL;
}

void insert(NODE *ht[size],int rno, char* name)
{
    int index=rno%size;
    NODE *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->rno=rno;
    strcpy(temp->name,name);
    temp->next=NULL;
    if(ht[index]==NULL)
    {
        ht[index]=temp;
        return;
    }
    NODE *p=ht[index];
    while(p->next!=NULL)
    p=p->next;
    p->next=temp;
}

int delete(NODE *ht[size],int rno)
{
    int index=rno%size;
    NODE *p=ht[index],*q=NULL;
    while(p!=NULL && p->rno!=rno)
    {
        q=p;
        p=p->next;
    }
    if(p!=NULL)
    {
        if(q==NULL)
        ht[index]=p->next;
        else
        q->next=p->next;
        free(p);
        return 1;
    }
    return 0;
}

int search(NODE *ht[size],int rno,char *name)
{
    int index=rno%size;
    NODE *p=ht[index];
    while(p!=NULL)
    {
        if(p->rno==rno)
        {
            strcpy(name,p->name);
            return 1;
        }
        p=p->next;
    }
    return 0;
}

void display(NODE *ht[size])
{
int i;
NODE *p;
for(i=0;i<size;i++)
    {
        p=ht[i];
        printf("%d:",i);
        while(p!=NULL)
        {
        printf("%d",p->rno);
        printf("%s->",p->name);
        p=p->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    NODE *ht[size];
    initTable(ht);

    int choice,rno;
    char name[30];
    printf("1.INSERT 2.DELETE 3.SEARCH 4.DISPLAY");
    scanf("%d",&choice);
    do{
        switch(choice)
        {
    case 1:printf("enter the rno:");
    scanf("%d",&rno);
    printf("Enter name:");
    scanf("%s",name);
    insert(ht,rno,name);
    break;

    case 2:printf("enter the rno:");
    scanf("%d",&rno);
    if(delete(ht,rno))
    printf("record with rno %d is deleted",rno);
    else
    printf("record not found");
    break;

    case 3:printf("enter the rno:");
    scanf("%d",&rno);
    if(search(ht,rno,name))
    printf("Record found: Details %d %s\n",rno,name);
    else
    printf("record not found");
    break;

    case 4:display(ht);
    break;
        }
printf("1.INSERT 2.DELETE 3.SEARCH 4.DISPLAY");
    scanf("%d",&choice);
    }while(choice<5);
}