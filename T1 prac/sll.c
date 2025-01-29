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

// Function to convert an array to a linked list
struct Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL; // Handle empty array case

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    //printf("NULL\n");
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


// my prac
void del(struct Node** headRef, int k) {
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



// Main function to test the code
int main() {
    int arr[] = {1, 3, 4, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = arrayToLinkedList(arr, size);

    printf("Linked List: ");
    printLinkedList(head);

    printf("New ll: ");
    del(&head, 2);
    printLinkedList(head);



    // Free the allocated memory for the linked list
    freeLinkedList(head);
    return 0;
}
