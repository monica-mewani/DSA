#include <stdio.h>
#define MAX 100

struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return value;
    }
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
