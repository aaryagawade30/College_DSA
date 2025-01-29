#include <stdio.h>
#include <stdlib.h>

// Define a stack structure
#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to sort a stack using another temporary stack
void sortStack(Stack* mainStack) {
    Stack tempStack;
    init(&tempStack);

    while (!isEmpty(mainStack)) {
        int temp = pop(mainStack);

        // Move elements from tempStack back to mainStack if they are greater than temp
        while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
            push(mainStack, pop(&tempStack));
        }
        
        // Place the current element in tempStack
        push(&tempStack, temp);
    }

    // Move elements back to the main stack, now sorted in ascending order
    while (!isEmpty(&tempStack)) {
        push(mainStack, pop(&tempStack));
    }

}

// Helper function to print stack elements
void printStack(Stack* stack) {
    // for (int i = 0; i <= stack->top; i++) {
    //     printf("%d ", stack->arr[i]);
    // }

    for(int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Test the function
int main() {
    Stack mainStack;
    init(&mainStack);

    // Push elements onto the main stack
    push(&mainStack, 34);
    push(&mainStack, 3);
    push(&mainStack, 31);
    push(&mainStack, 98);
    push(&mainStack, 92);
    push(&mainStack, 23);

    printf("Original Stack:\n");
    printStack(&mainStack);

    // Sort the stack
    sortStack(&mainStack);

    printf("Sorted Stack in Ascending Order:\n");
    printStack(&mainStack);

    return 0;
}
