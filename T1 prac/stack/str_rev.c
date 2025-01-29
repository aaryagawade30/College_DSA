#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100  // Define a suitable max size for the stack

// Define the stack structure
struct stack {
    char stk[MAX];
    int top;
} st;

// Check if the stack is empty
int isEmpty() {
    return (st.top == -1);
}

// Check if the stack is full
int isFull() {
    return (st.top == MAX - 1);
}

// Push an element onto the stack
void push(char val) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    } else {
        st.top++;
        st.stk[st.top] = val;
    }
}

// Pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return '\0'; // Return null character if stack is empty
    } else {
        return st.stk[st.top--];
    }
}

// Function to reverse a string using the stack
void reverseString(char str[]) {
    int n = strlen(str);
    st.top = -1; // Initialize the stack

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    // Pop all characters from the stack and put them back in the string
    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string to reverse: ");
    scanf("%99s", str); // Read a string using scanf, limiting to 99 characters

    printf("Original String: %s\n", str);

    // Reverse the string using the stack
    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
