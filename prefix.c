#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct stack
{
    char *exp;
    int *arr;
    int top;
} stack;
void push(stack *p, int n)
{
    p->arr[++p->top] = n;
}
int pop(stack *p)
{
    return p->arr[p->top--];
}
int compute(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    }
}
int prefixEval(stack p)
{
    char exp[1000];
    strcpy(exp, p.exp);
    int num = 0;
    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] != '+' && exp[i] != '*' && exp[i] != '/' && exp[i] != '-' && exp[i] != '^' && exp[i] != ' ')
            num = num * 10 + (int)exp[i] - 48;
        else if (exp[i] == '+' exp[i] == '*' exp[i] == '/' exp[i] == '-' exp[i] == '^')
        {
            int a = pop(&p);
            int b = pop(&p);
            int c = compute(a, b, exp[i]);
            push(&p, c);
        }
        else
        {
            if (num != 0)
            {
                push(&p, num);
                num = 0;
            }
        }
    }
    return pop(&p);
}
int main()
{
    stack p;
    p.top = -1;
    p.exp = (char *)malloc(1000 * sizeof(char));
    p.arr = (int *)malloc(1000 * sizeof(int));
    printf("Enter the prefix expression: ");
    scanf("%[^\n]", p.exp);
    p.exp = strrev(p.exp);
    printf("Value of the expression: %d", prefixEval(p));
}