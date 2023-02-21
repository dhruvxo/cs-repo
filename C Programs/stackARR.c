#include<stdio.h>
#define MAX 10

typedef struct stack{
    int top;
    int s[MAX];
}STACK;

void initStack(STACK *ps) //*ps is pointer to the typedef structure
{
ps->top=-1;
}

int isFull(STACK *ps)
{
    return ps->top==MAX-1; //if it returns 0, stack isnt full
}

int isEmpty(STACK *ps)
{
    return ps->top==-1; //if it returns 0, stack isnt empty
}

int push(STACK *ps, int ele)
{
    if(isFull(ps))
    printf("Stack Overflow!");
    return 0;
    ps->top++;
    ps->s[ps->top]=ele;
    return 1;
}

int pop(STACK *ps, int *pe) //*pe is used to store the element which gets popped
{
    if(isEmpty(ps))
    {
        printf("Stack Underflow! (No elements)");
        return 0;
    }
    *pe=ps->s[ps->top];
    ps->top--;
    return 1;
}

int peek(STACK *ps, int *pe)
{
     if(isEmpty(ps))
    {
        return 0;
    }
    *pe=ps->s[ps->top];
    return 1;
}

void display(STACK *ps)
{
    if(isEmpty(ps))
    {
        printf("Stack is Empty.");
        return;
    }
    for(int i=ps->top;i>-1;i--)
    {
        printf("%d",ps->s[i]);
        printf("\n");
    }
}

int main()
{
  STACK s;
  int choice,ele;
  
	  printf("\n 1.Push\n 2.Pop\n 3.Peek\n 4.isEmpty\n 5.isFull\n 6.Display\n");
	  printf("enter your choice:");
	  scanf("%d",&choice);
    do
	{
	  switch(choice)
	  {
		    case 1:printf("enter the element to be pushed:\n");
				   scanf("%d",&ele);
                   if(push(&s,ele))
				   printf("Pushed %d",ele);
                   else
                   printf("Stack Overflow!\n");
				   break;

			case 2://printf("enter the element to be popped:\n");
                    //scanf("%d",&ele);
                    if(pop(&s,&ele)) //address of element must be used because pass by reference because whatever is there in *pe will be popped instead of its actual value
                    printf("Popped %d",ele);
                    else
                    printf("Stack Underflow!\n");
                    break;

            case 3: if(peek(&s,&ele))
                    printf("stack top is %d",ele);
                    else
                    printf("Stack is Empty\n");
                    break;

            case 4: if(isEmpty(&s))
                    printf("stack is empty\n");
                    else
                    printf("stack contains elements");
                    break;

            case 5: if(isFull(&s))
                    printf("Stack is Full\n");
                    else
                    printf("Stack isn't full\n");
                    break;

			case 6:display(&s);
				   break;
	  }
      printf("\n 1.Push\n 2.Pop\n 3.Peek\n 4.isEmpty\n 5.isFull\n 6.Display\n");
	  printf("enter your choice:");
	  scanf("%d",&choice);
  }while(choice<7);
  return 0;
}