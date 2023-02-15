#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;
}NODE;

typedef struct dll
{
	NODE *head;
}DLL;

void initList(DLL *dll)
{
	dll->head=NULL;
}
NODE * getnode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
void insertFront(DLL *dll,int ele)
{
	NODE *temp=getnode(ele);
	temp->next=dll->head;
	if(dll->head!=NULL)
		dll->head->prev=temp;
	dll->head=temp;	
}
void insertLast(DLL *dll,int ele)
{
	NODE *temp=getnode(ele);
	NODE *p=dll->head;
	if(dll->head==NULL)
	{
		dll->head=temp;
		return;
	}
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
	temp->prev=p;
}
void display(DLL *dll)
{
	NODE *p=dll->head;
	if(dll->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void insertAtPos(DLL *dll,int ele,int pos)
{
	NODE *p=dll->head, *q=NULL;
	NODE *temp=getnode(ele);
	if(pos==0)
	{
		temp->next=dll->head;
		if(dll->head!=NULL)
			dll->head->prev=temp;
		dll->head=temp;
		return;
	}
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->prev=q;
	temp->next=p;
	p->prev=temp;	
}
void deleteLast(DLL *dll)
{
	NODE *p=dll->head;
	if(dll->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(p->next==NULL)
	{
		dll->head=NULL;
		printf("%d\n",p->data);
		free(p);
		return;
	}
	while(p->next!=NULL)
		p=p->next;
	p->prev->next=NULL;
	printf("%d\n",p->data);
	free(p);
}
void deleteFront(DLL *dll)
{
	NODE *p=dll->head;
	if(dll->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(dll->head->next==NULL)
	{
		dll->head=NULL;
		printf("%d\n",p->data);
		free(p);
		return;
	}
	dll->head=p->next;
	dll->head->prev=NULL;
	printf("%d\n",p->data);
	free(p);
}
void deleteAtPos(DLL *dll,int pos)
{
	NODE *p=dll->head,*q=NULL,*n=NULL;
	if(dll->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(pos==0)
	{
		dll->head=p->next;
		printf("%d\n",p->data);
		free(p);
		return;
	}
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	if(p->next==NULL)
	{
		q->next=NULL;
		printf("%d\n",p->data);
		free(p);
		return;
	}
	q->next=p->next;
	n=p->next;
	n->prev=q;
}
void search(DLL *dll,int key)
{
	NODE *p=dll->head;
	int i=0;
	while(p->data!=key && p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	if(p->data==key)
	{
		printf("key %d is present at location %d\n",p->data,i+1);
		
	}
	else
		printf("Unsuccessful search\n");
}
void reverseList(DLL *dll)
{
	NODE *p=dll->head;
	while(p->next!=NULL)
		p=p->next;
	dll->head=p;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->prev;
	}
	return;
}
int main()
{
    int ele,pos,ch;
	DLL dobj;
	initList(&dobj);
	do{
		printf("1.InsertFront 2.InsertLast 3.InsertAtPos 4.Display\n");
		printf("6.DeleteFront 7.DeleteLast 8.DeleteAtPos 5.Destroy\n");
		printf("9.search 10.reverseList 11.delAlt\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter ele");
				   scanf("%d",&ele);
				   insertFront(&dobj,ele);
				   break;
			case 2:printf("enter ele");
				   scanf("%d",&ele);
				   insertLast(&dobj,ele);
				   break;
			case 3:printf("enter ele");
				   scanf("%d",&ele);
				   printf("enter the pos:");
				   scanf("%d",&pos);
				   insertAtPos(&dobj,ele,pos);
				   break;
			case 4:display(&dobj);
					break;
			/* case 5:destroyList(&dobj);
				   break; */
			case 6:deleteFront(&dobj);
			       break;
			case 7:deleteLast(&dobj);
			       break;
			case 8:printf("enter pos:");
				   scanf("%d",&pos);
				   deleteAtPos(&dobj,pos);
			       break;
			case 9:printf("enter the key:");
				   scanf("%d",&ele);
				   search(&dobj,ele);
				   break;
			case 10:reverseList(&dobj);
				    //display(&dobj);
					break;
			/*case 11:delAlt(&dobj);
					display(&dobj);
					break; */
		}
	}while(ch);
	return 0;
}