#include <stdio.h>
#include <stdlib.h>
#define MAX 100  // Define the maximum capacity of the stack

// Structure to represent a stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Initialize top to -1 indicating an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an element to the stack (push)
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d.\n", element);
    } else {
        stack->arr[++stack->top] = element;
        printf("Pushed %d into the stack.\n", element);
    }
}

// Function to remove the top element from the stack (pop)
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;  // Return -1 to indicate an error
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to return the top element without removing it (peek)
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Main function to test the stack operations
int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));
    printf("Popped element is %d\n", pop(&stack));
    printf("Top element after pop is %d\n", peek(&stack));

    return 0;
}
