#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct cll
{
    NODE* last;
}CLL;

// void initList(CLL*);
// void insertFront(CLL*,int);
// void insertLast(CLL*,int);
// void insertAtPos(CLL*,int,int);
// void display(CLL*);
// void destroyList(CLL*);
// void deleteFront(CLL*,int);
// void deleteLast(CLL*,int);


void initList(CLL *cll)
{
	cll->last=NULL;
}

//NODE * getNode(int ele)
// {
// 	NODE *temp=malloc(sizeof(NODE));
// 	temp->data=ele;
// 	temp->next=NULL;
// 	return temp;
// }

 void insertFront(CLL * cll,int ele)
 {
 	NODE *temp=malloc(sizeof(NODE));
    temp->data=ele;
    if(cll->last=NULL)
    {
        cll->last=temp;
        temp->next=temp;
        return;
    }
    temp->next=cll->last->next;
    cll->last->next=temp;
}
void insertLast(CLL* cll,int ele)
{
	NODE *temp=getNode(ele);
	if(cll->head==NULL)
	{
		cll->head=temp;
		return;
	} 
	NODE *p=cll->head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}
int countnodes(CLL *cll)
{
	int count=0;
	if(cll->head==NULL)
		return 0;
	NODE *p=cll->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
void insertAtPos(CLL *cll,int ele,int pos)
{
	//int n=countnodes(cll);
	NODE *temp=getNode(ele);
	if(pos==0)
	{
		temp->next=cll->last->next;
		cll->last->next=temp;
		return;
	}
	NODE *p=cll->last->next, *q=NULL;
	for(int i=1;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}
void display(CLL* cll)
{
	if(cll->last==NULL)
	{
		printf("List is empty");
		return;
	}
	NODE *p=cll->last->next;
    do{
    printf("%d\n",p->data);
		p=p->next;
    }
	while(p!=cll->last);
}  
void destroyList(CLL * cll)
{
	NODE *p=cll->last->next;
	while(p!=NULL)
	{
		NODE *q=p; 
		printf("%d\n",p->data);
		p=p->next;
		free(q);
	}
	cll->last->next=NULL;
}

int main()
{
  CLL lobj;
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