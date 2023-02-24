#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 50

int precedence(char ch)
{
        switch (ch)
        {
        case ')':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
                return 3;
        default:
                return 0;
        }
}

void push(long int x, long int *stk, int *top)
{
        if (*top > SIZE)
        {
                printf("Stack Overflow\n");
                exit(1);
        }
        else
        {
                *top = (*top) + 1;
                stk[*top] = x;
        }
}

long int pop(long int *stk, int *top)
{
        if (*top == -1)
        {
                printf("Stack Underflow \n");
                return -99999;
        }
        return (stk[(*top)--]);
}
int isEmpty(int *top)
{
        if (*top == -1)
                return 1;
        else
                return 0;
}

int isSpace(char ch)
{
        if (ch == ' ' || ch == '\t' || ch == '\0')
                return 1;
        else
                return 0;
}

long int eval_prefix(char *prefix, long int *stk, int *top)
{
        long int A, B, t;
        int i;

        for (i = strlen(prefix) - 1; i >= 0; i--)
        {
                if (prefix[i] <= '9' && prefix[i] >= '0')
                        push(prefix[i] - 48, stk, top);
                else
                {
                        B = pop(stk, top);
                        A = pop(stk, top);
                        switch (prefix[i])
                        {
                        case '+':
                                t = B + A;
                                break;
                        case '-':
                                t = B - A;
                                break;
                        case '*':
                                t = B * A;
                                break;
                        case '/':
                                t = B / A;
                                break;
                        case '%':
                                t = B % A;
                                break;
                        case '^':
                                t = pow(B, A);
                        }
                        push(t, stk, top);
                }
        }
        return pop(stk, top);
}

void infix_to_prefix(char *infix, char *prefix, long int *stk, int *top)
{
        int i, j, p, n;
        char next;
        char symbol;
        char temp;
        n = strlen(infix);
        p = 0;
        for (i = n - 1; i >= 0; i--)
        {
                symbol = infix[i];
                if (!isSpace(symbol))
                {
                        switch (symbol)
                        {
                        case ')':
                                push(symbol, stk, top);
                                break;
                        case '(':
                                while ((next = pop(stk, top)) != ')')
                                        prefix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
                                while (!isEmpty(top) && precedence(stk[*top]) > precedence(symbol))
                                        prefix[p++] = pop(stk, top);
                                push(symbol, stk, top);
                                break;
                        default:
                                prefix[p++] = symbol;
                        }
                }
        }
        while (!isEmpty(top))
                prefix[p++] = pop(stk, top);
        prefix[p] = '\0';

        for (i = 0, j = p - 1; i < j; i++, j--)
        {
                temp = prefix[i];
                prefix[i] = prefix[j];
                prefix[j] = temp;
        }
}

int main()
{
        int top;
        char infix[SIZE], prefix[SIZE];
        long int stk[SIZE];

        int no_of_char;
        long int value;
        top = -1;

        scanf("%d", &no_of_char);
        gets(infix);

        infix_to_prefix(&infix, &prefix, &stk, &top);
        printf("%s ", prefix);

        value = eval_prefix(&prefix, &stk, &top);
        printf("%ld", value);
        return 0;
}
