#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
        default: return -1;
    }
}
int isoperator(char op)
{
    return (op=='+'|| op=='-' || op=='*' || op=='/' || op=='*');
}
char *infix2postfix(char *infix)
{
    int len=strlen(infix);
    int i,j;
    int top=-1;
    char stack[MAX];
    char *postfix=malloc(sizeof(char)*(len));
    for(i=0,j=0;i<len;i++)
    {
        if(isalnum(infix[i]))
        postfix[j++]=infix[i];
        else if(infix[i]=='(')
        stack[++top]=infix[i];
        else if(infix[i]==')')
        {
         while(top>-1 && stack[top]!='(')
         postfix[j++]=stack[top--];
         if(top>-1 && stack[top]!='(')
         return "invalid expression";
         else
         top--;   
        }
        else if(isoperator(infix[i]))
        {
            while(top>-1 && precedence(infix[i])<precedence(stack[top]))
            // if(precedence(infix[i])>stack[top])
            postfix[j++]=stack[top--];
            stack[++top]=infix[i];
        }
    }
    while(top>-1){
        if(stack[top]=='(')
        return "invalid expression";
    postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char infix[MAX];
    printf("enter the infix expression: ");
    gets(infix);
    char *postfix=infix2postfix(infix);
    printf("postfix expression is: %s",postfix);
    free(postfix);
    return 0;
}