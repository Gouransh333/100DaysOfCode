Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Create a new deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Push at front
void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;
    if (dq->front != NULL) dq->front->prev = newNode;
    dq->front = newNode;
    if (dq->rear == NULL) dq->rear = newNode;
    dq->size++;
}

// Push at rear
void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (dq->rear != NULL) dq->rear->next = newNode;
    dq->rear = newNode;
    if (dq->front == NULL) dq->front = newNode;
    dq->size++;
}

// Pop from front
int pop_front(Deque* dq) {
    if (dq->front == NULL) return -1;
    Node* temp = dq->front;
    int val = temp->data;
    dq->front = dq->front->next;
    if (dq->front != NULL) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->size--;
    return val;
}

// Pop from rear
int pop_back(Deque* dq) {
    if (dq->rear == NULL) return -1;
    Node* temp = dq->rear;
    int val = temp->data;
    dq->rear = dq->rear->prev;
    if (dq->rear != NULL) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->size--;
    return val;
}

// Get front element
int front(Deque* dq) {
    return dq->front ? dq->front->data : -1;
}

// Get rear element
int back(Deque* dq) {
    return dq->rear ? dq->rear->data : -1;
}

// Check if empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// Get size
int size(Deque* dq) {
    return dq->size;
}

// Clear deque
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Display deque
void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 20);
    push_back(dq, 30);
    display(dq); // 20 10 30

    printf("Front: %d\n", front(dq)); // 20
    printf("Back: %d\n", back(dq));   // 30

    pop_front(dq);
    pop_back(dq);
    display(dq); // 10

    clear(dq);
    printf("Empty? %s\n", empty(dq) ? "Yes" : "No");

    return 0;
}
