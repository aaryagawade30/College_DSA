#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int number;
    struct stack *next;

} *top, *p, *q;

void display()
{
    q = top;
    if (q == NULL)
        printf("Empty Stack");
    else
    {
        while (q != NULL)
        {
            printf("%d", q->number);
            q = q->next;
        }
    }
    printf("\n");
}

void push()
{
    p = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter data to be pushed: ");
    scanf("%d", &p->number);
    p->next = NULL;

    if (top == NULL)
        top = p;
    else
    {
        p->next = top;
        top = p; // we are moving top from back to front to get at head***
    }
}

int pop()
{
    if (top == NULL)
        return 0;
    else
    {
        p = top;
        int x = p->number;
        top = top->next;
        p->next = NULL;
        free(p);
        return x;
    }
}

int main()
{
    int x, ch;
    top = NULL;
    do
    {
        printf("Enter choice: 1. Push, 2. Pop, 3. Display, 4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            display();
            break;

        case 2:
            x = pop();
            if (x != 0)
            {
                printf("Popped element: %d", x);
                printf("\n");
                display();
            }
            else
                printf("Empty stack");
            break;

        case 3:
            display();
            break;

        default:
            exit(0);
        }

    } while (ch != 4);

    return 0;
}