#include <stdio.h>
#include <stdlib.h>

/*
1. Initialize an empty stack to hold the opening parentheses '(','{', and '['.

2. Begin scanning the expression from left to right.

3. If an opening parenthesis '(', '{', or '[' is encountered, push it onto the stack.

4. If a closing parenthesis ')', '}', or ']' is encountered:
    a. Check if the stack is empty. If it is, the expression is not balanced, and you return 0.
    b. Pop the top element from the stack.
    c. <this is an additional step for multiple parenthesis matching> Check if the popped opening parenthesis matches the current closing parenthesis using the match() function. If they match, continue. If not, the expression is not balanced, and you return 0.

5. Repeat steps 3-4 for each character in the expression.

6. After scanning the entire expression, if the stack is empty, you return 1 to indicate a balanced expression. If the stack is not empty, you return 0 to indicate an unbalanced expression.
*/

struct stack
{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

char stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "[4-6((8){(9-8)})]";

    if (parenthesisMatch(exp))
    {
        printf("balanced");
    }
    else
    {
        printf("not balanced");
    }
    return 0;
}
