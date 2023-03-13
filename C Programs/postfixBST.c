#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 1000
typedef struct node{
    char info;
    struct node *left,*right;
}NODE;

NODE *root=NULL;
typedef struct stack
{
    NODE *s[max];
    int top;
}STACK;

void initStack(STACK *ps)
{
    ps->top=-1;
}

int push(STACK *ps,NODE *e)
{
    if(ps->top==max-1)
    return 0;
    ps->top++;
    ps->s[ps->top]=e;
    return 1;
}
NODE *pop(STACK *ps)
{
    NODE *t=ps->s[ps->top];
    ps->top--;
    return t;
}

float eval(NODE *r)
{
    float res;
    switch(r->info)
    {
        case '+':res=eval(r->left)+eval(r->right);
        break;
        case '-':res=eval(r->left)-eval(r->right);
        break;
        case '*':res=eval(r->left)*eval(r->right);
        break;
        case '/':res=eval(r->left)/eval(r->right);
        break;
        default: return r->info-'0';
    }
    return res;
}

int main()
{
    char postfix[max];
    int i=0;
    STACK sobj;
    NODE *temp;
    initStack(&sobj);
    //initTree(&tobj);
    printf("Enter the postfix expression:\n");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        temp=malloc(sizeof(NODE));
        temp->info=postfix[i];
        temp->left=NULL;
        temp->right=NULL;
        if(isdigit(postfix[i]))
        push(&sobj,temp);
        else
        {
            temp->right=pop(&sobj);
            temp->left=pop(&sobj);
            push(&sobj,temp);
        }
    i++;
    }
root=pop(&sobj);
printf("%f\n",eval(root));
return 0;
}