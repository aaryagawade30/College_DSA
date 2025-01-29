#include <stdio.h>
#include <stdlib.h>
struct node
{
    int number;
    struct node *next;
};
void display(struct node *curr);
void disp_rev(struct node *curr);

int main()
{
    struct node *head = NULL, *curr, *p, *q, *r;
    int ch, c1, find, pos, n, search;
    char c;
    curr = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &curr->number);

    head = curr;

    do
    {
        printf("want to create a node (y/n) ? ");
        scanf(" %c", &c);
        if (c == 'y')
        {
            curr->next = (struct node *)malloc(sizeof(struct node));
            curr = curr->next;
            printf("enter the data: ");
            scanf("%d", &curr->number);
        }
    } while (c == 'y' || c == 'Y');
    curr->next = NULL;
    display(head);

    do
    {
        printf("\nMENU: \n1.Search \n2.Insertion \n3.Deletion \n4.Reverse \n5.Revert");
        printf("\nEnter the choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // search
            printf("Enter the number you want to search: ");
            scanf("%d", &search);
            curr = head;
            while (find == 0 && curr != NULL)
            {
                if (curr->number == search)
                {
                    find = 1;
                    break;
                }

                else
                {
                    pos++;
                    curr = curr->next;
                }
            }
            if (find == 1)
            {
                printf("%d found %d", search, pos + 1);
            }
            else
            {
                printf("not found");
            }
            break;
        case 2: // insert
            p = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d", &p->number);
            p->next = NULL;
            printf("Insertion at 1.beg 2.end 3.mid");
            scanf("%d", &c1);
            if (c1 == 1)
            {
                p->next = head;
                head = p;
            }
            else if (c1 == 2)
            {
                curr = head;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = p;
            }
            else
            {
                curr = head;
                printf("enter after which node u want insertion: ");
                scanf("%d", &n);
                while (curr->number != n)
                {
                    curr = curr->next;
                }
                p->next = curr->next;
                curr->next = p;
            }
            display(head);
            break;
        case 3: // delete
            printf("deletion at 1.beg 2.end 3.mid");
            scanf("%d", &c1);
            if (c1 == 1)
            {
                p = head;
                head = head->next;
                free(p);
            }
            else if (c1 == 2)
            {
                curr = head;
                while (curr->next->next != NULL)
                {
                    curr = curr->next;
                }
                p = curr->next;
                curr->next = NULL;
                free(p);
            }
            else
            {
                printf("Enter which node you want to delete the node: ");
                scanf("%d", &n);
                curr = head;
                while (curr->next->number != n)
                {
                    curr = curr->next;
                }
                p = curr->next;
                curr->next = p->next;
                p->next = NULL;
                free(p);
            }
            display(head);
            break;
        case 4:
            p = head;
            q = NULL;
            while (p != NULL)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }
            head = q;
            q = NULL;

            display(head);
            break;
        case 5: // reverse
            printf("Reversed linked list by not actually reversing it:");
            disp_rev(head);
            break;
        default:
            printf("invalid choice");
        }
    } while (ch != 6);
    return 0;
}

void display(struct node *curr)
{
    if (curr == NULL)
        printf("list empty");
    else
    {
        while (curr != NULL)
        {
            printf("%d\t", curr->number);
            curr = curr->next;
        }
    }
}

void disp_rev(struct node *curr)
{
    if (curr != NULL)
    {
        disp_rev(curr->next);
        printf("\t%d", curr->number);
    }
}