#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
 {
  int info;
  bool rthread;
  struct node *left;
  struct node *right;
 }NODE;

typedef struct tree
 {
  NODE *root;
 }TREE;

void init(TREE *pt)
 {
  pt->root=NULL;
 }


NODE* createNode(int e)
{
 NODE* temp=malloc(sizeof(NODE));
 temp->info=e;
 temp->left=NULL;
 temp->right=NULL;
 temp->rthread=1;
 return temp;
}

void setLeft(NODE* q,int e)
{
 NODE* temp=createNode(e);
 q->left=temp;
 temp->right=q;
}

void setRight(NODE* q,int e)
{
 NODE* temp=createNode(e);
 temp->right=q->right;
 q->right=temp;
 q->rthread=0;
}

void inOrder(TREE *t)
{
 NODE *p=t->root;
 NODE *q;
    do{
       q=NULL;

     while(p!=NULL)
      {
       q=p;
       p=p->left;
      }

     if(q!=NULL)
      {
       printf("%d ",q->info);
       p=q->right;


       while(q->rthread && p!=NULL)
       {
         printf("%d ",p->info);
         q=p;
         p=p->right;
       }
     }
  }

   while(q!=NULL);
}

void create(TREE *pt)
{
 NODE *p,*q;
 int e,choice;

 printf("Enter root info\n");
 scanf("%d",&e);

 pt->root=createNode(e);
  do{
     printf("Enter info of next node\n");
     scanf("%d",&e);
     p=pt->root;
     q=NULL;

while(p!=NULL)
{
 q=p;
 if(e<p->info)
 p=p->left;

 else{
   if(p->rthread)
    p=NULL;
  else
    p=p->right;
     }
}

if(e < q->info)
setLeft(q,e);


else
setRight(q,e);
printf("Add element ? \n");
scanf("%d",&choice);

   }while(choice);
}

int main()
{
 TREE t;
 init(&t);
 create(&t);
 inOrder(&t);
 return 0;
}