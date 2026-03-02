Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.

#include <stdio.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(struct Node nodes[], int* index, int data) {
    nodes[*index].data = data;
    nodes[*index].next = NULL;
    nodes[*index].prev = NULL;
    return &nodes[(*index)++];
}
struct Node* insertEnd(struct Node* head, struct Node nodes[], int* index, int data) {
    struct Node* newNode = createNode(nodes, index, data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
void printForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node nodes[n];
    int idx = 0;
    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        head = insertEnd(head, nodes, &idx, arr[i]);
    }

    printForward(head);

    return 0;
}
