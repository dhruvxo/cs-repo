#include<stdio.h>
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

void initList(LLIST*);
void insertFront(LLIST*,int);
void insertLast(LLIST*,int);
void insertAtPos(LLIST*,int,int);
void display(LLIST*);
void destroyList(LLIST*);
void deleteFront(LLIST*,int);
void deleteLast(LLIST*,int);


void initList(LLIST *sll)
{
	sll->head=NULL;
}

NODE * getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->next=NULL;
	return temp;
}

void insertFront(LLIST * sll,int ele)
{
	NODE *temp=getNode(ele);
	temp->next=sll->head;
	sll->head=temp;
}
void insertLast(LLIST* sll,int ele)
{
	NODE *temp=getNode(ele);
	if(sll->head==NULL)
	{
		sll->head=temp;
		return;
	} 
	NODE *p=sll->head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}
int countnodes(LLIST *sll)
{
	int count=0;
	if(sll->head==NULL)
		return 0;
	NODE *p=sll->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void insertAtPos(LLIST *sll,int ele,int pos)
{
	//int n=countnodes(sll);
	NODE *temp=getNode(ele);
	if(pos==0)
	{
		temp->next=sll->head;
		sll->head=temp;
		return;
	}
	NODE *p=sll->head, *q=NULL;
	for(int i=1;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}
void display(LLIST* sll)
{
	if(sll->head==NULL)
	{
		printf("List is empty");
		return;
	}
	NODE *p=sll->head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("\n");
}  
void destroyList(LLIST * sll)
{
	NODE *p=sll->head;
	while(p!=NULL)
	{
		NODE *q=p; 
		printf("%d\n",p->data);
		p=p->next;
		free(q);
	}
	sll->head=NULL;
}

int main()
{
  LLIST lobj;
  initList(&lobj);
  int choice,ele,pos;
  
  do{
	  printf("1.Insert Front\n 2. Insert Last\n 3.Insert at pos\n 4.display\n 5.destroy\n");
	  printf("enter your choice:");
	  scanf("%d",&choice);
	  
	  switch(choice)
	  {
		    case 1:printf("enter an integer\n");
				   scanf("%d",&ele);
				   insertFront(&lobj,ele);
				   break;
			case 2:printf("enter an integer\n");
				   scanf("%d",&ele);
				   insertLast(&lobj,ele);
				   break;
			case 3:printf("enter an integer\n");
				   scanf("%d",&ele);
				   printf("enter the pos:");
				   scanf("%d",&pos);
				   insertAtPos(&lobj,ele,pos);
				   break;
			case 4:display(&lobj);
				   break;
	  }
  }while(choice<5);
  destroyList(&lobj);
  return 0;
}