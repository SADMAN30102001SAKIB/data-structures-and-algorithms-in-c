#include <stdio.h>
#define MAX_SIZE 5

struct pqueue
{
    int data;
    int priority;
};
struct pqueue pq[MAX_SIZE];
int rear = -1;

int isEmpty()
{
    return rear == -1;
}

int isFull()
{
    return rear == MAX_SIZE - 1;
}

void enqueueDescending(int elm, int p)
{
    if (!isFull())
    {
        int i;
        for (i = rear; p > pq[i].priority && i >= 0; i--)
        {
            pq[i + 1].data = pq[i].data;
            pq[i + 1].priority = pq[i].priority;
        }

        rear++;
        pq[i + 1].data = elm;
        pq[i + 1].priority = p;
    }
    else
    {
        printf("Full\n");
    }
}

void deleteDescendingHighestPriority()
{
    if (!isEmpty())
    {
        int elm = pq[0].data;
        int p = pq[0].priority;
        for (int i = 0; i < rear; i++)
        {
            pq[i].data = pq[i + 1].data;
            pq[i].priority = pq[i + 1].priority;
        }
        rear--;

        printf("Deleted %d with priority %d\n", elm, p);
    }
    else
    {
        printf("Empty\n");
    }
}

void display()
{
    if (!isEmpty())
    {
        for (int i = 0; i <= rear; i++)
        {
            printf("data -> %d, priority -> %d\n", pq[i].data, pq[i].priority);
        }
    }
    else
    {
        printf("Empty\n");
    }
}

int main()
{
    display();
    enqueueDescending(2, 5);
    enqueueDescending(1, 3);
    enqueueDescending(4, 8);
    enqueueDescending(3, 0);
    enqueueDescending(6, 2);
    enqueueDescending(5, 7);
    display();

    deleteDescendingHighestPriority();
    display();

    enqueueDescending(5, 7);
    display();

    return 0;
}