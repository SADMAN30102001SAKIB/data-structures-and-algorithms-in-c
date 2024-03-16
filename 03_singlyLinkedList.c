#include <stdio.h>
#include <stdlib.h>

/*
Linked List real-life usage:
i) Undo/Redo Functionality
ii) Browser visited site back/forward History
iii) Music player list
*/

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Dynamic memory allocation is used because we can't return a normal local variable's(structure) address via function(it'll be destryed out of it's scope, because it is getting memory form stack) & since need to track all the node's address, we have to get memory from the heap
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node **head, struct Node **tail, int value)
{
    struct Node *newNode = createNode(value); // temporary node to store data

    if (*head == NULL) // for 1st insertion
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode; // move the tail node forward
    }
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int findLength(struct Node *head)
{
    struct Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

int searchNode(struct Node *head, int key)
{
    struct Node *current = head;
    int index = 0;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;
}

void insertNodeAtIndex(struct Node **head, struct Node **tail, int value, int index, int length)
{
    if (index < 0 || index > length)
    {
        printf("Invalid index\n");
    }
    else if (*head == NULL)
    {
        appendNode(head, tail, value);
    }
    else if (index == 0)
    {
        struct Node *newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
    }
    else if (index == length)
    {
        struct Node *newNode = createNode(value);
        (*tail)->next = newNode;
        *tail = newNode; // move the tail node forward
    }
    else
    {
        struct Node *current = *head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        // now current is at the previous node of the given index

        struct Node *newNode = createNode(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNodeAtIndex(struct Node **head, struct Node **tail, int index, int length)
{
    struct Node *current = *head;

    if (index < 0 || index > length - 1)
    {
        printf("Invalid index\n");
    }
    else if (*head == NULL)
    {
        printf("Empty list!\n");
    }
    else if (index == 0)
    {
        *head = (*head)->next;
        free(current);
    }
    else if (index == length - 1)
    {

        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        // now current is at the previous node of the last node

        struct Node *temp = current->next;
        *tail = current; // move the tail node backward
        (*tail)->next = NULL;
        free(temp);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        // now current is at the previous node of the given index

        struct Node *temp = current->next;
        current->next = (current->next)->next;
        free(temp);
    }
}

void reverseList(struct Node **head, struct Node **tail)
{
    if (*head != NULL)
    {
        struct Node *nextNode;        // this will shift to the nextNode of current node & will be responsible to update the current node to next node
        struct Node *prev = NULL;     // this prev's NULL will be stored in the head's next at 1st, then store the current node's address
        struct Node *current = *head; // will be responsible for storing the previous node's address in current node's next
        while (current != NULL)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        // now both current & nextNode is holding NULL, but prev is holding the last node's address

        // swap head & tail
        *tail = *head;
        *head = prev;
    }
}

void merge(struct Node **tail, struct Node **head2, struct Node **tail2)
{
    (*tail)->next = *head2;
    *tail = *tail2;
}

int main()
{
    struct Node *head = NULL; // head pointer that points the head node
    struct Node *tail = head; // pointer to track the current last node for next insertion
    struct Node *head2 = NULL;
    struct Node *tail2 = head2;
    int choice, value;

    // traversing
    do
    {
        printf("Do you want to add a node in 1st list (0/1): ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the value: ");
            scanf("%d", &value);
            appendNode(&head, &tail, value);
        }
    } while (choice == 1);

    do
    {
        printf("Do you want to add a node in 2nd list (0/1): ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the value: ");
            scanf("%d", &value);
            appendNode(&head2, &tail2, value);
        }
    } while (choice == 1);

    printf("Linked list 1: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    printf("Linked list 2: ");
    printList(head2);
    printf("Length: %d\n", findLength(head2));

    // searching
    int key;
    printf("Enter a value to search in list 1: ");
    scanf("%d", &key);
    int index = searchNode(head, key);
    if (index != -1)
    {
        printf("Value found at index: %d\n", index);
    }
    else
    {
        printf("Value not found\n");
    }

    // insertion
    printf("Enter a value to insert in list 1: ");
    scanf("%d", &value);
    printf("Enter the index to insert: ");
    scanf("%d", &index);
    insertNodeAtIndex(&head, &tail, value, index, findLength(head));

    printf("Linked list 1 after insertion: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    // deletion
    printf("Enter the index to delete in list 1: ");
    scanf("%d", &index);
    deleteNodeAtIndex(&head, &tail, index, findLength(head));

    printf("Linked list 1 after deletion: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    // reversing
    reverseList(&head, &tail);
    printf("Reversed linked list 1: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    // merging
    merge(&tail, &head2, &tail2);
    printf("merged list 1 & 2: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
