#include <stdio.h>
#include <stdlib.h>

// DEQueue using circular array
/*
DEQueue real-life usage:
i) Multi-processor's A-Steal algorithm
*/

#define MAX_SIZE 100
int deque[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty()
{
    return (front == -1 && rear == -1);
}

int isFull()
{
    return (front == (rear + 1) % MAX_SIZE);
}

void insertFront(int value)
{
    if (isFull())
    {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque[front] = value;
}

void insertRear(int value)
{
    if (isFull())
    {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    deque[rear] = value;
}

int removeFront()
{
    if (isEmpty())
    {
        printf("Deque is empty. Cannot remove.\n");
        return -1;
    }

    int removedValue = deque[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }

    return removedValue;
}

int removeRear()
{
    if (isEmpty())
    {
        printf("Deque is empty. Cannot remove.\n");
        return -1;
    }

    int removedValue = deque[rear];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return removedValue;
}

int getFront()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque[front];
}

int getRear()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque[rear];
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX_SIZE;
    }

    printf("\n");
}

int main()
{
    insertFront(2);
    insertRear(3);
    insertFront(1);
    insertRear(4);

    display();

    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());

    removeFront();
    removeRear();

    display();

    return 0;
}
