#include<stdio.h>
#define max 50
typedef struct priq
{
    int pq[max];
    int n;
}PQ;

void init(PQ *pt)
{
    pt->n=0;
}

void display(PQ *pt)
{

}

void display(PQ *pt)
{
    for(int i=0;i<pt->n;i++)
    printf("%d",pt->pq[i]);
}

int enqueue(PQ *pt,int e)
{
    int p,c;
    if(pt->n==max-1) return 0;
    pt->pq[pt->n]=e;
    c=pt->n;
    p=(c-1)/2;
    while(c>0 && pt->pq[p]<e)
    {
        pt->pq[c]=pt->pq[p];
        c=p;
        p=(c-1)/2;
    }
    pt->pq[c]=e;
    pt->n=pt->n+1;
    return 1;
}

int dequeue(PQ *pt,int e)
{
    int p,c;
    if(pt->n==0) return 0;
    *e=pt->pq[0];
    int elt=pt->pq[pt->n-1];
    p=0;
    if(pt->n==1)
    c=-1;
    else c=1;
    if(pt->n>2 && pt->pq[2]>pt->pq[1])
    c=c+1;
    while(c>=0 && elt<pt->pq[c])
    {
        pt->pq[p]=pt->pq[c];
        p=c;
        c=2*p+1;
        if(c+1<=pt->n-1)&&pt->pq[c+1]>pt->pq[c])
        c=c+1;
        if(c>=pt->n-1) c=-1;
    }
    pt->pq[p]=elt;
    pt->n=pt->n-1;
    return 1;
}

int main()
{
    PQ pobj;
    int ch,k,ele;
    init(&pobj);
    printf("1.Enqueue 2.Dequeue 3.Display\n");
    
    switch(ch)
    {
        case 1: printf("enter the ele:");
        scanf("%d",&ele);
        enqueue(&pobj,ele);
        break;
        case 2: k=dequeue(&pobj,&ele);
        if(!k) 
        printf("queue underflow");
        else
        printf("dequeued:%d",ele);
        break;
        case 3: display(&pobj);
        break;
    }
    printf("1.Enqueue 2.Dequeue 3.Display\n");
}