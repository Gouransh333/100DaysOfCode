Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node nodes[n];  
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        nodes[i].data = val;
        nodes[i].next = NULL;
  if (i == 0) {
            head = &nodes[i];
        } else {
            nodes[i - 1].next = &nodes[i];
        }
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
