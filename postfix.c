#include <stdio.h>
#include <ctype.h>
#define MAX 20

typedef struct stack
{
    int data[MAX];
    int top;
} stack;

int evaluate(char x, int op1, int op2)
{
    if (x == '+')
        return (op1 + op2);
    if (x == '-')
        return (op1 - op2);
    if (x == '*')
        return (op1 * op2);
    if (x == '/')
        return (op1 / op2);
    if (x == '%')
        return (op1 % op2);
}

void init(stack *s)
{
    s->top = -1;
}

int empty(stack *s)
{
    if (s->top == -1)
        return (1);
    return (0);
}

int full(stack *s)
{
    if (s->top == MAX - 1)
        return (1);
    return (0);
}

void push(stack *s, int x)
{
    s->top = s->top + 1;
    s->data[s->top] = x;
}

int pop(stack *s)
{
    int x;
    x = s->data[s->top];
    s->top = s->top - 1;
    return (x);
}
int main()
{
    stack s;
    char x;
    int op1, op2, val;
    init(&s);
    printf("Enter the expression : ");
    char arr[MAX];
    scanf("%s", arr);
    int size;
    size = strlen(arr);

    int i = 0;

    while (i < size)
    {
        if (isdigit(arr[i]))
            push(&s, arr[i] - 48);
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            val = evaluate(arr[i], op1, op2);
            push(&s, val);
        }
        i++;
    }
    val = pop(&s);
    printf("Value of expression = %d\n", val);

    return 0;
}
