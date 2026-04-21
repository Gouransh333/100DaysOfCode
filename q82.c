Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Queue {
    int front, rear, size, capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFullStack(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmptyStack(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (!isFullStack(stack))
        stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (!isEmptyStack(stack))
        return stack->array[stack->top--];
    return -1;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmptyQueue(struct Queue* queue) {
    return queue->size == 0;
}

int isFullQueue(struct Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(struct Queue* queue, int item) {
    if (!isFullQueue(queue)) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size++;
    }
}

int dequeue(struct Queue* queue) {
    if (!isEmptyQueue(queue)) {
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return item;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Queue* queue = createQueue(n);
    struct Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(queue, x);
    }

    while (!isEmptyQueue(queue)) {
        push(stack, dequeue(queue));
    }

    while (!isEmptyStack(stack)) {
        int val = pop(stack);
        printf("%d ", val);
    }

    return 0;
}