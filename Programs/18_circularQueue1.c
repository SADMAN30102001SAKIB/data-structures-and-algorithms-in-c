#include <stdio.h>
#define MAX_SIZE 5

// Using circular array

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty()
{
    return (front == -1 && rear == -1);
}

void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Error value
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return item;
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty. Nothing to peek.\n");
        return -1; // Error value
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty. Nothing to display.\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;
        while (i != rear)
        {
            printf("%d, ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[i]);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    printf("Peek: %d\n", peek());

    printf("Dequeued: %d\n", dequeue());

    display();

    enqueue(6);
    enqueue(7);

    display();

    return 0;
}
