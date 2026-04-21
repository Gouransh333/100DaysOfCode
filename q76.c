Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[index] < heap->arr[parent]) {
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MinHeap *heap, int x) {
    if (heap->size == MAX_SIZE) {
        return; // Heap full
    }
    heap->arr[heap->size] = x;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

int peek(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    return heap->arr[0];
}

int main() {
    int N;
    scanf("%d", &N);
    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < N; i++) {
        char command[20];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(&heap, x);
        } else if (strcmp(command, "extractMin") == 0) {
            printf("%d\n", extractMin(&heap));
        } else if (strcmp(command, "peek") == 0) {
            printf("%d\n", peek(&heap));
        }
    }
    return 0;
}
