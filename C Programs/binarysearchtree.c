#include<stdio.h>

typedef struct node
{
    int info;
    struct node *left, *right;
}NODE;

typedef struct tree
{
    NODE *root;
}TREE;

void init(TREE *pt)
{
    pt->root=NULL;
}

void main()
{
    TREE tobj;
    init(&tobj);
    printf("Enter root info");
    scanf(",);
}