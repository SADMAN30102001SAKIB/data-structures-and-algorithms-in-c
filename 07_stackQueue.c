#include <stdio.h>
#include <stdlib.h>

// Stack & Queue using linkedlist
/*
Stack real-life usage:
i) Browser visited site back/forward History
ii) Text Editors' Undo/Redo Functionality
iii) Expression Evaluation (parenthesis matching)
iv) Recursion call stack
v) string reversal
*/

/*
Queue real-life usage:
i) Operating System Process Scheduler
ii) Task Scheduler (Email sending)
*/

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

int pop(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    struct Node *p = *head;
    if (p->next == NULL)
    {
        int d = p->data;
        free(p);
        *head = NULL;

        return d;
    }
    else
    {
        *head = (*head)->next;
        int d = p->data;
        free(p);
        return d;
    }
}

void enqueue(struct Node **head, struct Node **tail, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int dequeue(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    struct Node *p = *head;
    if (p->next == NULL)
    {
        int d = p->data;
        free(p);
        *head = NULL;

        return d;
    }
    else
    {
        *head = (*head)->next;
        int d = p->data;
        free(p);
        return d;
    }
}

void display(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct Node *stack = NULL;
    struct Node *queueFront = NULL;
    struct Node *queueRear = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    printf("Stack elements:\n");
    display(stack);

    printf("popping: %d\n", pop(&stack));
    printf("Stack elements after popping:\n");
    display(stack);

    printf("pushing: %d\n", 0);
    push(&stack, 0);
    printf("Stack elements after popping:\n");
    display(stack);

    printf("popping: %d\n", pop(&stack));
    printf("Stack elements after popping:\n");
    display(stack);

    enqueue(&queueFront, &queueRear, 6);
    enqueue(&queueFront, &queueRear, 7);
    enqueue(&queueFront, &queueRear, 8);
    enqueue(&queueFront, &queueRear, 9);
    printf("\nQueue elements:\n");
    display(queueFront);

    printf("dequeueing: %d\n", dequeue(&queueFront));
    printf("Queue elements after dequeueing:\n");
    display(queueFront);

    printf("enqueueing: %d\n", 0);
    enqueue(&queueFront, &queueRear, 0);
    printf("Queue elements after dequeueing:\n");
    display(queueFront);

    printf("dequeueing: %d\n", dequeue(&queueFront));
    printf("Queue elements after dequeueing:\n");
    display(queueFront);

    return 0;
}
