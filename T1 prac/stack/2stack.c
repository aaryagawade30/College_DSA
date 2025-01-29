#include <stdio.h>
#include <stdlib.h>

struct TwoStacks {
    int *array;   // Array to hold the two stacks
    int top1;     // Top index of Stack1
    int top2;     // Top index of Stack2
    int capacity; // Capacity of the array
};

// Initialize the stacks with a given capacity
struct TwoStacks* createTwoStacks(int capacity) {
    struct TwoStacks *stacks = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
    stacks->capacity = capacity;
    stacks->array = (int*)malloc(capacity * sizeof(int));
    stacks->top1 = -1;
    stacks->top2 = capacity;
    return stacks;
}

// Push to Stack1
void push1(struct TwoStacks* stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) { // Check for space between two stacks
        stacks->array[++stacks->top1] = value;
    } else {
        printf("Stack1 Overflow\n");
    }
}

// Push to Stack2
void push2(struct TwoStacks* stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) { // Check for space between two stacks
        stacks->array[--stacks->top2] = value;
    } else {
        printf("Stack2 Overflow\n");
    }
}

// Pop from Stack1
int pop1(struct TwoStacks* stacks) {
    if (stacks->top1 >= 0) {
        int value = stacks->array[stacks->top1--];
        return value;
    } else {
        printf("Stack1 Underflow\n");
        return -1; // Indicates underflow
    }
}

// Pop from Stack2
int pop2(struct TwoStacks* stacks) {
    if (stacks->top2 < stacks->capacity) {
        int value = stacks->array[stacks->top2++];
        return value;
    } else {
        printf("Stack2 Underflow\n");
        return -1; // Indicates underflow
    }
}

// Test the implementation
int main() {
    struct TwoStacks* stacks = createTwoStacks(10);

    // Push elements to Stack1
    push1(stacks, 5);
    push1(stacks, 10);
    push1(stacks, 15);

    // Push elements to Stack2
    push2(stacks, 20);
    push2(stacks, 25);
    push2(stacks, 30);

    // Pop elements from Stack1
    printf("Popped from Stack1: %d\n", pop1(stacks));
    printf("Popped from Stack1: %d\n", pop1(stacks));

    // Pop elements from Stack2
    printf("Popped from Stack2: %d\n", pop2(stacks));
    printf("Popped from Stack2: %d\n", pop2(stacks));

    // Free allocated memory
    free(stacks->array);
    free(stacks);

    return 0;
}
