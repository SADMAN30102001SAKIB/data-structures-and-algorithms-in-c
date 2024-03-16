#include <stdio.h>
#include <stdlib.h>

// DEQueue using Doubly Linked List

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    return (front == NULL && rear == NULL);
}

void insertFront(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
}

int removeFront()
{
    if (isEmpty())
    {
        printf("Deque is empty. Cannot remove.\n");
        return -1;
    }

    int removedValue = front->data;
    struct Node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
    return removedValue;
}

int removeRear()
{
    if (isEmpty())
    {
        printf("Deque is empty. Cannot remove.\n");
        return -1;
    }

    int removedValue = rear->data;
    struct Node *temp = rear;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
    return removedValue;
}

int getFront()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return -1;
    }

    return front->data;
}

int getRear()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return -1;
    }

    return rear->data;
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return;
    }

    struct Node *current = front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
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
