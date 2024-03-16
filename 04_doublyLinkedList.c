#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Dynamic memory allocation is used because we can't return a normal local variable's(structure) address via function(it'll be destryed out of it's scope, because it is getting memory form stack) & since need to track all the node's address, we have to get memory from the heap
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendNode(struct Node **head, struct Node **tail, int value)
{
    struct Node *newNode = createNode(value); // temporary node to store data

    if (*head == NULL) // for 1st insertion
    {
        *head = newNode;
        *tail = newNode;
        return;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode; // move the tail node forward
    }
}

void printList(struct Node *head)
{
    struct Node *current = head;
    if (head != NULL)
    {
        printf("NULL <- ");
        while (current != NULL)
        {
            if (current->next != NULL)
            {
                printf("%d <--> ", current->data);
            }
            else
            {
                printf("%d -> ", current->data);
            }
            current = current->next;
        }
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
        (*head)->prev = newNode;
        *head = newNode;
    }
    else if (index == length)
    {
        struct Node *newNode = createNode(value);
        (*tail)->next = newNode;
        newNode->prev = *tail;
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
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
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
        if (*head == NULL) // if all nodes are deleted
        {
            *tail = NULL;
        }
        else
        {
            (*head)->prev = NULL;
        }

        free(current);
    }
    else if (index == length - 1)
    {
        struct Node *temp = *tail;
        *tail = (*tail)->prev;
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
        (current->next)->prev = current;
        free(temp);
    }
}

void reverseList(struct Node **head, struct Node **tail)
{
    if (*head != NULL)
    {
        struct Node *current = *head; // will be responsible for storing the previous node's address in current node's next & for storing the next node's address in current node's prev
        struct Node *nextNode;        // just a type of temp variable that will be responsible for updating the current node to next node
        while (current != NULL)
        {
            // swap all node's next & prev
            nextNode = current->next;
            current->next = current->prev;
            current->prev = nextNode;
            current = nextNode;
        }
        // now both current & nextNode is holding NULL

        // swap head & tail
        current = *head;
        *head = *tail;
        *tail = current;
    }
}

void merge(struct Node **tail, struct Node **head2, struct Node **tail2)
{
    (*tail)->next = *head2;
    (*head2)->prev = *tail;
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
        printf("Do you want to add a node in list 1 (0/1): ");
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
        printf("Do you want to add a node in list 2 (0/1): ");
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
    printf("Enter a value to search: ");
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
    printf("Enter a value to insert: ");
    scanf("%d", &value);
    printf("Enter the index to insert: ");
    scanf("%d", &index);
    insertNodeAtIndex(&head, &tail, value, index, findLength(head));

    printf("Linked list after insertion: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    // deletion
    printf("Enter the index to delete: ");
    scanf("%d", &index);
    deleteNodeAtIndex(&head, &tail, index, findLength(head));

    printf("Linked list after deletion: ");
    printList(head);
    printf("Length: %d\n", findLength(head));

    // reversing
    reverseList(&head, &tail);
    printf("Reversed linked list: ");
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
