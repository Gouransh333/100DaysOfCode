Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.


#include <stdio.h>
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
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
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

    int result = countOccurrences(head, key);
    printf("%d\n", result);

    return 0;
}
