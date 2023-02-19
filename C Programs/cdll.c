#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev,*next;
}NODE;

typedef struct cdll{
    NODE *head;
}CDLL;

void initList(CDLL *cdll)
{
    cdll->head=NULL;
}

void initList(CDLL*);
void insertFront(CDLL*,int);
// void insertLast(CDLL*,int);
// void insertAtPos(CDLL*,int,int);
void display(CDLL*);	
// void destroyList(CDLL*);
// void deleteFront(CDLL*,int);
// void deleteLast(CDLL*,int);
// void initList(CDLL *cdll)
// {
// 	cdll->head=NULL;
// }

// NODE * getNode(int ele)
// {
// 	NODE *temp=malloc(sizeof(NODE));
// 	temp->data=ele;
// 	temp->next=NULL;
// 	return temp;
// }

void insertFront(CDLL * cdll,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	if(cdll->head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        cdll->head=temp;
        return;
    }
    temp->next=cdll->head;
    temp->prev=cdll->head->prev;
    cdll->head->prev->next=temp;
    cdll->head->prev=temp;
    cdll->head=temp;
}
void insertLast(CDLL* cdll,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	if(cdll->head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        cdll->head=temp;
        return;
    }
    temp->next=cdll->head;
    temp->prev=cdll->head->prev;
    cdll->head->prev->next=temp;
    cdll->head->prev=temp;

}
// void insertAtPos(CDLL *cdll,int ele,int pos)
// {
// 	//int n=countnodes(cdll);
// 	NODE *temp=gmalloc(sizeof(NODE));
// 	temp->data=ele;
// if(cdll->head==NULL)
// {
// 	temp->next=temp;
// 	temp->prev=temp;
// 	cdll->head=temp;
// 	return;
// }
// NODE *p-cdll->head,*q=NULL;
// for(i=0,i<pos;i++)
// {
	
// }
//}

void display(CDLL* cdll)
{
    NODE *p=cdll->head;
	if(cdll->head==NULL)
	{
		printf("List is empty");
		return;
	}
    do{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=cdll->head);
}  
// void destroyList(CDLL * cdll)
// {
// 	NODE *p=cdll->head;
// 	while(p!=NULL)
// 	{
// 		NODE *q=p; 
// 		printf("%d\n",p->data);
// 		p=p->next;
// 		free(q);
// 	}
// 	cdll->head=NULL;
// }

void deleteFront(CDLL *cdll)
{
	if(cdll->head=NULL)
	{
		printf("List is Empty");
		return;
	}
	NODE *p=cdll->head->next;
	if(p->next==p)
	{
		cdll->head=NULL;
	printf("%d\n",p->data);
	free(p);
	return;
	}
	// NODE *p=cdll->head;
	cdll->head->next=p->next;
	cdll->head->prev=p->prev;
	p->prev->next=cdll->head;
	printf("%d\n",p->data);
	free(p);
}

int main()
{
  CDLL dobj;
  initList(&dobj);
  int choice,ele,pos;
  
  do{
	  printf("\n 1.Insert Front\n 2.Insert Last\n 3.Insert at Pos\n 4.Display\n 5.DeleteFront\n");
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
			// case 3:printf("enter an integer\n");
			// 	   scanf("%d",&ele);
			// 	   printf("enter the pos:");
			// 	   scanf("%d",&pos);
			// 	   insertAtPos(&dobj,ele,pos);
			// 	   break;
			case 4:display(&dobj);
				   break;
			case 5:deleteFront(&dobj);
				   break;
	  }
  }while(choice);
  return 0;
}