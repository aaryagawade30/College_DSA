#include <stdio.h>
#include <stdlib.h>

#define MAX 32 // Assuming maximum 32 bits for integer representation

// Define the st structure
struct Stack {
    int arr[MAX];
    int top;
}st;

// Function to initialize the st
void initStack(struct Stack* st) {
    st->top = -1;
}

// Function to check if the st is full
int isFull(struct Stack* st) {
    return st->top == MAX - 1;
}

// Function to check if the st is empty
int isEmpty(struct Stack* st) {
    return st->top == -1;
}

// Function to push an item to the st
void push(struct Stack* st, int value) {
    if (isFull(st)) {
        printf("Stack overflow\n");
        exit(1); // Exit if st overflows
    }
    st->arr[st->top++] = value;
}

// Function to pop an item from the st
int pop(struct Stack* st) {
    if (isEmpty(st)) {
        printf("Stack underflow\n");
        exit(1); // Exit if st underflows
    }
    return st->arr[st->top--];
}

// Function to convert decimal to binary using st
void decimalToBinary(int num) {
    struct Stack st;
    initStack(&st);

    // Edge case: if the number is 0
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Push remainders to the st
    while (num > 0) {
        push(&st, num % 2);
        num /= 2;
    }

    // Pop and print binary representation
    printf("Binary: ");
    while (!isEmpty(&st)) {
        printf("%d", pop(&st));
    }
    printf("\n");
}

// Main function to test the code
int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    decimalToBinary(num);

    return 0;
}
