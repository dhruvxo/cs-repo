#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

typedef struct cll
{
	NODE * last;
}CLL;

void initList(CLL *cll)
{
	cll->last=NULL;
}
void insertFront(CLL *cll,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	if(cll->last==NULL)
	{
		cll->last=temp;
		temp->next=temp;
		return;
	}
	temp->next=cll->last->next;
	cll->last->next=temp;
}
void insertLast(CLL *cll,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	if(cll->last==NULL)
	{
		cll->last=temp;
		temp->next=temp;
		return;
	}
	temp->next=cll->last->next;
	cll->last->next=temp;
	cll->last=temp;
}
int countnodes(CLL *cll)
{
	int count=0;
	if(cll->last==NULL)
		return 0;
	else{
		NODE *p=cll->last->next;
		while(p!=cll->last)
		{
			p=p->next;
			count++;
		}
		count++;
		return count;
	}
}
void insertAtPos(CLL *cll,int ele,int pos)
{
	int c=countnodes(cll);
	if(pos>c || pos<0)
	{
		printf("invalid pos\n");
		return;
	}
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	if(pos==0)
	{
		if(cll->last==NULL)
		{
			cll->last=temp;
			temp->next=temp;
			return;
		}
		else{
			temp->next=cll->last->next;
			cll->last->next=temp;
			return;
		}
	}
	NODE *p=cll->last->next,*q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
	if(pos==c)
	{
		cll->last=temp;
	}	
}
void deleteFront(CLL *cll)
{
	if(cll->last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	NODE *p=cll->last->next;
	if(p->next==p)
	{
		cll->last=NULL;
		printf("%d\n",p->data);
		free(p);
		return;
	}
	cll->last->next=p->next;
	printf("%d\n",p->data);
	free(p);
}
void deleteLast(CLL *cll)
{
	if(cll->last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	NODE *p=cll->last->next;
	if(p->next==p)
	{
		cll->last=NULL;
		printf("%d\n",p->data);
		free(p);
		return;
	}
	while(p->next!=cll->last)
		p=p->next;
	p->next=cll->last->next;
	printf("%d\n",cll->last->data);
	free(cll->last);
	cll->last=p;
}
void deleteAtPos(CLL *cll,int pos)
{
	if(cll->last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	int c=countnodes(cll);
	if(pos<0 || pos>c){
		printf("invalid pos\n");
		return;
	}
	NODE *p=cll->last->next,*q=NULL;
	if(pos==0)
	{	
		cll->last->next=p->next;
		printf("%d\n",p->data);
		if(p->next==p)
			cll->last=NULL;
		free(p);
		return;
	}
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	printf("%d\n",p->data);
	if((pos+1)==c)
	 cll->last=q;
	free(p);
}
void display(CLL *cll)
{
	if(cll->last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	NODE *p=cll->last->next;
	do{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=cll->last);
	printf("%d\n",p->data);
}
void destroyList(CLL *cll)
{
	if(cll->last=NULL)
	{
		printf("List is Empty\n");
		return;
	}
	NODE *p=cll->last->next,*q=NULL;
	while(p!=cll->last)
	{
		q=p;
		p=p->next;
		free(p);
		cll->last->next=NULL;
	}
}
	
int main()
{
    int ele,pos,ch;
	CLL lobj;
	initList(&lobj);
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
				   insertFront(&lobj,ele);
				   break;
			case 2:printf("enter ele");
				   scanf("%d",&ele);
				   insertLast(&lobj,ele);
				   break;
			case 3:printf("enter ele");
				   scanf("%d",&ele);
				   printf("enter the pos:");
				   scanf("%d",&pos);
				   insertAtPos(&lobj,ele,pos);
				   break;
			case 4:display(&lobj);
					break;
			case 5:destroyList(&lobj);
				   break;
			case 6:deleteFront(&lobj);
			       break;
			case 7:deleteLast(&lobj);
			       break;
			case 8:printf("enter pos:");
				   scanf("%d",&pos);
				   deleteAtPos(&lobj,pos);
			       break;
			/* case 9:printf("enter the key:");
				   scanf("%d",&ele);
				   search(&lobj,ele);
				   break;
			case 10:reverseList(&lobj);
				    display(&lobj);
					break;
			case 11:delAlt(&lobj);
					display(&lobj);
					break; */
		}
	}while(ch);
	return 0;
}