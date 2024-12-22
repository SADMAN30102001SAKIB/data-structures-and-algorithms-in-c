#include <stdio.h>
#include <stdlib.h>

// Using circular linked list

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Enqueued: %d\n", value);
}

int dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = front->data;
    struct Node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
    printf("Dequeued: %d\n", value);
    return value;
}

int peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }

    return front->data;
}

void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }

    struct Node *current = front;

    while (current->next != front)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    display();

    printf("Peek: %d\n", peek());

    dequeue();
    dequeue();

    display();

    enqueue(5);

    display();

    return 0;
}
