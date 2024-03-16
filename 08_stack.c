#include <stdio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX_SIZE - 1;
}

void push(int item)
{
    if (isFull())
    {
        printf("Stack Overflow: Cannot push more elements.\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to the stack.\n", item);
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
        return -1;
    }
    int item = stack[top--];
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    push(10);
    push(20);
    display();

    push(30);
    display();

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    display();

    return 0;
}
