#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int number;
    struct queue *next;
} *p, *q, *front, *rear;

void enqueue()
{
    p = (struct queue *)malloc(sizeof(struct queue));
    printf("Enter data to be pushed: ");
    scanf("%d", &p->number);
    p->next = NULL;

    if (rear == NULL)
    {
        rear = p;
        front = p;
    }
    else
    {
        rear->next = p;
        rear = rear->next;
    }
}

void dequeue()
{
    q = front;
    if (q == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("Deleted element: %d\n", front->number);
        front = front->next;
        q->next = NULL;
        free(q);
    }
}

void display()
{
    q = front;
    if (q == NULL)
    {
        printf("Empty Queue");
    }

    else
    {
        while (q != NULL)
        {
            printf("%d", q->number);
            q = q->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    rear = NULL;
    front = NULL;

    do
    {
        printf("Enter option: 1. Enqueue, 2. Dequeue, 3. Display\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1: // enqueue
            enqueue();
            display();
            break;

        case 2: // dequeue
            dequeue();
            display();
            break;

        case 3: // display
            display();
            break;

        default:
            exit(0);
        }

    } while (ch != 4);

    return 0;
}