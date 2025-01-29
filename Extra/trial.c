#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int number;
    struct node *next;
};

// Function to display the linked list
void display(struct node *curr)
{
    if (curr == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (curr != NULL)
        {
            printf("%d\t", curr->number);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Function to display the linked list in reverse order (recursive)
void display_rev(struct node *curr)
{
    if (curr != NULL)
    {
        display_rev(curr->next);
        printf("%d\t", curr->number);
    }
}

// Function to reverse the linked list
struct node *revert(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev to current
        curr = next;        // Move to the next node
    }
    return prev;  // New head of the reversed list
}

// Function to insert a node
struct node *insert_node(struct node *head)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    int c2, n;

    printf("Enter data: ");
    scanf("%d", &p->number);
    p->next = NULL;

    printf("Insert at 1. Beginning 2. End 3. Anywhere in middle\n");
    scanf("%d", &c2);

    // Insert at the beginning
    if (c2 == 1)
    {
        p->next = head;
        head = p;
    }
    // Insert at the end
    else if (c2 == 2)
    {
        struct node *curr = head;
        if (curr == NULL)
        {
            head = p; // Handle empty list
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = p;
        }
    }
    // Insert at a specific position
    else if (c2 == 3)
    {
        printf("Enter the node number after which to insert the new node: ");
        scanf("%d", &n);

        struct node *curr = head;
        while (curr != NULL && curr->number != n)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            printf("Node with value %d not found.\n", n);
            free(p); // Free the unused node
        }
        else
        {
            p->next = curr->next;
            curr->next = p;
        }
    }
    else
    {
        printf("Invalid option.\n");
        free(p);
    }

    return head;
}

// Function to delete a node
struct node *delete_node(struct node *head)
{
    int c3, key;
    struct node *curr, *prev;

    if (head == NULL) // Check for empty list
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    printf("Delete: 1. Beginning 2. End 3. Specific Value\n");
    scanf("%d", &c3);

    // Delete at the beginning
    if (c3 == 1)
    {
        curr = head;
        head = head->next; // Update the head to the next node
        free(curr);        // Free the removed node
        printf("Deleted node at the beginning.\n");
    }
    // Delete at the end
    else if (c3 == 2)
    {
        curr = head;

        if (head->next == NULL) // Single node case
        {
            free(head);
            head = NULL;
            printf("Deleted the last node.\n");
            return head;
        }

        while (curr->next != NULL) // Traverse to the second last node
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL; // Unlink the last node
        free(curr);        // Free the last node
        printf("Deleted node at the end.\n");
    }
    // Delete a specific value
    else if (c3 == 3)
    {
        printf("Enter the value to delete: ");
        scanf("%d", &key);

        curr = head;

        // Check if the head node has the target value
        if (head->number == key)
        {
            head = head->next; // Update the head
            free(curr);        // Free the old head
            printf("Deleted node with value %d at the beginning.\n", key);
            return head;
        }

        // Traverse the list to find the target value
        while (curr != NULL && curr->number != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) // Value not found
        {
            printf("Value %d not found in the list.\n", key);
        }
        else
        {
            prev->next = curr->next; // Unlink the node
            free(curr);              // Free the node
            printf("Deleted node with value %d.\n", key);
        }
    }
    else
    {
        printf("Invalid option. Try again.\n");
    }
    return head;
}

int main()
{
    struct node *head = NULL, *curr;
    int ch;
    char c1;

    // Create the initial linked list
    do
    {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &curr->number);
        curr->next = head;
        head = curr;

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &c1);

    } while (c1 == 'y' || c1 == 'Y');

    display(head);

    // Menu-driven program
    do
    {
        printf("\n1. Insert\t2. Delete\t3. Revert\t4. Display reverse\t5. Display\t6. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insert_node(head);
            display(head);
            break;

        case 2:
            head = delete_node(head);
            display(head);
            break;

        case 3:
            head = revert(head);
            printf("Reverted linked list:\n");
            display(head);
            break;

        case 4:
            printf("List in reverse order:\n");
            display_rev(head);
            printf("\n");
            break;

        case 5:
            display(head);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid option. Try again.\n");
        }
    } while (ch != 6);

    return 0;
}
