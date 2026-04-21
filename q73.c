Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;


void insert(int x) {
    pq[size++] = x;
}


int delete() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    int val = pq[minIndex];
 
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return val;
}


int peek() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return pq[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);
    char op[10];
    int val;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}

