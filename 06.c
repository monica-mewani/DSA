#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed: %d\n", data);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        struct Node* temp = *top;
        int data = temp->data;
        *top = (*top)->next;
        free(temp);
        return data;
    }
}

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    printf("Popped: %d\n", pop(&top));
    printf("Popped: %d\n", pop(&top));

    return 0;
}
