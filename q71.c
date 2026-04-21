Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct {
    Node* front;
    Node* rear;
} CircularQueue;


CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(CircularQueue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


void dequeue(CircularQueue* q) {
    if (q->front == NULL) return; 
    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
}

void display(CircularQueue* q) {
    if (q->front == NULL) return;
    Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    int n, m, val;
    scanf("%d", &n);

    CircularQueue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    return 0;
}
