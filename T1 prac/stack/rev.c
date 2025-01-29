#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stack {
    int stk[MAX];
    int top;
} st;

// Check if stack is empty
int isEmpty(int size) {
    return (size == -1);
}

// Check if stack is full
int isFull(int size) {
    return (size == MAX - 1);
}

// Push an element onto the stack
void push(int val) {
    if (isFull(st.top)) {
        printf("Full Stack\n");
        return;
    } else {
        st.top++;
        st.stk[st.top] = val;
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty(st.top)) {
        printf("Empty Stack\n");
        return -1; // Return -1 to indicate empty stack
    } else {
        int rem = st.stk[st.top];
        st.top--;
        return rem;
    }
}

// Function to reverse an array using stack
void revArr(int arr[], int size) {
    st.top = -1; // Initialize the stack
    for (int i = 0; i < size; i++) {
        push(arr[i]); // Push array elements onto the stack
    }
    for (int i = 0; i < size; i++) {
        arr[i] = pop(); // Pop elements back into the array in reverse order
    }
}


int main() {
    int arr[MAX] = {2, 4, 4, 6, 1};

    printf("Original Array: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reverse the array
    revArr(arr, MAX);

    printf("Reversed Array: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
