#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node at the end of the list
void appendNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove all elements greater than k from the linked list
void removeElementsGreaterThanK(struct Node** headRef, int k) {
    struct Node* current = *headRef;
    struct Node* prev = NULL;

    // Handle nodes at the head of the list
    while (current != NULL && current->data > k) {
        *headRef = current->next;
        free(current);
        current = *headRef;
    }

    // Traverse the list and remove nodes greater than k
    while (current != NULL) {
        if (current->data > k) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the code
int main() {
    struct Node* head = NULL;
    int k = 3;

    // Create a linked list with some test values
    int arr[] = {1, 4, 2, 5, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        appendNode(&head, arr[i]);
    }

    printf("Original Linked List: ");
    printLinkedList(head);

    removeElementsGreaterThanK(&head, k);

    printf("Linked List after removing elements greater than %d: ", k);
    printLinkedList(head);

    // Free the allocated memory for the linked list
    freeLinkedList(head);

    return 0;
}
