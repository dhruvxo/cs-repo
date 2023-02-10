#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev,*next;
}NODE;

typedef struct dll{
    NODE *head;
}DLL;

void initList(DLL *dll)
{
    dll->head=NULL;
}

void initList(LLIST*);
void insertFront(LLIST*,int);
void insertLast(LLIST*,int);
void insertAtPos(LLIST*,int,int);
void display(LLIST*);
void destroyList(LLIST*);
void deleteFront(LLIST*,int);
void deleteLast(LLIST*,int);


void initList(LLIST *dll)
{
	dll->head=NULL;
}

NODE * getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->next=NULL;
	return temp;
}

void insertFront(LLIST * dll,int ele)
{
	NODE *temp=getNode(ele);
	temp->next=dll->head;
	dll->head=temp;
}
void insertLast(LLIST* dll,int ele)
{
	NODE *temp=getNode(ele);
	if(dll->head==NULL)
	{
		dll->head=temp;
		return;
	} 
	NODE *p=dll->head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}
int countnodes(LLIST *dll)
{
	int count=0;
	if(dll->head==NULL)
		return 0;
	NODE *p=dll->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void insertAtPos(LLIST *dll,int ele,int pos)
{
	//int n=countnodes(dll);
	NODE *temp=getNode(ele);
	if(pos==0)
	{
		temp->next=dll->head;
		dll->head=temp;
		return;
	}
	NODE *p=dll->head, *q=NULL;
	for(int i=1;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}
void display(LLIST* dll)
{
	if(dll->head==NULL)
	{
		printf("List is empty");
		return;
	}
	NODE *p=dll->head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("\n");
}  
void destroyList(LLIST * dll)
{
	NODE *p=dll->head;
	while(p!=NULL)
	{
		NODE *q=p; 
		printf("%d\n",p->data);
		p=p->next;
		free(q);
	}
	dll->head=NULL;
}

int main()
{
  LLIST dobj;
  initList(&dobj);
  int choice,ele,pos;
  
  do{
	  printf("1.Insert Front\n 2. Insert Last\n 3.Insert at pos\n 4.display\n 5.destroy\n");
	  printf("enter your choice:");
	  scanf("%d",&choice);
	  
	  switch(choice)
	  {
		    case 1:printf("enter an integer\n");
				   scanf("%d",&ele);
				   insertFront(&dobj,ele);
				   break;
			case 2:printf("enter an integer\n");
				   scanf("%d",&ele);
				   insertLast(&dobj,ele);
				   break;
			case 3:printf("enter an integer\n");
				   scanf("%d",&ele);
				   printf("enter the pos:");
				   scanf("%d",&pos);
				   insertAtPos(&dobj,ele,pos);
				   break;
			case 4:display(&dobj);
				   break;
	  }
  }while(choice<5);
  destroyList(&dobj);
  return 0;
}