#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue
{
    int front, rear;
    int arr[MAX];

} q;

void enqueue()
{
    int num;
    if (q.rear == MAX - 1)
        printf("Queue full\n");
    else
    {
        int num;
        printf("Enter num: ");
        scanf("%d", &num);
        q.rear++;
        q.arr[q.rear] = num;
    }
}

void dequeue()
{
    int x;
    if (q.front == q.rear + 1)
        printf("Empty Queue");
    else
    {
        x = q.arr[q.front];
        q.front++;
        printf("Removed element: %d\n", x);
    }
}

void display()
{
    if (q.front == q.rear + 1)
        printf("Empty Queue");
    else
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d", q.arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    q.front = 0, q.rear = -1;

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