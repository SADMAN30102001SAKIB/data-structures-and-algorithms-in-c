#include <stdio.h>
#include <stdlib.h>

// Queue using stack

#define MAX_SIZE 100
int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int front1 = -1;
int front2 = -1;

int isEmpty1()
{
    return front1 == -1;
}

int isEmpty2()
{
    return front2 == -1;
}

int isFull1()
{
    return (front1 == MAX_SIZE - 1);
}

int isFull2()
{
    return (front2 == MAX_SIZE - 1);
}

void push(int val)
{
    stack1[++front1] = val;
    printf("enqueued %d\n", val);
}

int pop1()
{
    return stack1[front1--];
}

int pop2()
{
    return stack2[front2--];
}

void enqueue(int value)
{
    if (isFull1())
    {
        printf("Queue is full\n");
        return;
    }

    push(value);
}

int dequeue()
{
    if (isEmpty1())
    {
        printf("Queue is empty\n");
        return -1;
    }

    while (!isEmpty1())
    {
        stack2[++front2] = pop1();
    }

    int dequeuedValue = pop2();
    while (!isEmpty2())
    {
        stack1[++front1] = pop2();
    }
    return dequeuedValue;
}

void display()
{
    if (isEmpty1())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue:\n");
    for (int i = 0; i <= front1; i++)
    {
        printf("%d\n", stack1[i]);
    }

    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    enqueue(4);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    return 0;
}
