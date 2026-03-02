Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.


#include <stdio.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(struct Node nodes[], int* index, int data) {
    nodes[*index].data = data;
    nodes[*index].next = NULL;
    return &nodes[(*index)++];
}
struct Node* buildList(int arr[], int n, struct Node nodes[]) {
    if (n == 0) return NULL;
    int idx = 0;
    struct Node* head = createNode(nodes, &idx, arr[0]);
    struct Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(nodes, &idx, arr[i]);
        current = current->next;
    }
    return head;
}
struct Node* deleteKey(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head;

    prev->next = temp->next;
    return head;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
}

int main() {
    int n, key;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    struct Node nodes[n];
    struct Node* head = buildList(arr, n, nodes);
    head = deleteKey(head, key);
    printList(head);

    return 0;
}


