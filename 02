#include <stdio.h>
#include <ctype.h> // For isdigit() and isalpha()
#include <string.h> // For strlen()

#define MAX 100

// Stack structure definition
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char element) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = element;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

// Function to return the top element of the stack without popping it
char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return '\0';
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the output
        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(&stack, ch);
        }
        // If the character is ')', pop and output until '(' is found
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function to test the conversion
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
