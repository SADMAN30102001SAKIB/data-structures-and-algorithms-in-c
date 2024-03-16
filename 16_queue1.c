#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (front == -1)
        {
            // If the queue is empty, set both front and rear to 0
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Error value
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            // If there's only one element in the queue, reset front and rear
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return item;
    }
}

int peek()
{
    if (front == -1)
    {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (front == -1)
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
            i++;
        }
        printf("%d\n", queue[i]);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();

    printf("Peek: %d\n", peek());

    printf("Dequeued: %d\n", dequeue());

    display();

    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();

    return 0;
}
