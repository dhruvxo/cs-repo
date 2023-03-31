#include<stdio.h>
#include<string.h>
#define size 7

typedef struct student
{
    int Rno;
    char name[30];
    int mark;
}NODE;

void initTable(NODE ht[size],int *n)
{
    for(int i=0;i<size;i++)
    ht[i].mark=0;
    (*n)=0;
}

int insert(NODE ht[size],int Rno,char name[30],int *n)
{
    if(*n==size)
    return 0;
    int index=Rno%size;
    while(ht[index].mark!=0)
    index=(index+1)%size;
    ht[index].Rno=Rno;
    strcpy(ht[index].name,name);
    ht[index].mark=1;
    (*n)++;
    return 1;
}

int delete(NODE ht[size],int Rno,int *n)
{
    if(*n==0)
    return 0;
    int index=Rno%size;
    int i=1;
    while(ht[index].Rno!=Rno&&i<*n)
    {
        index=(index+i)%size;
        
    }
}