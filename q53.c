Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


// Create new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


// Insert at tail
Node* insertTail(Node* head, int val) {
    Node* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


// Get length of list
int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


// Find intersection node
Node* findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Move both together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}


int main() {
    int n, m;
    Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        head1 = insertTail(head1, arr1[i]);
    }

    scanf("%d", &m);
    int arr2[m];

    Node* intersectionNode = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    // Create second list and connect intersection manually
    for (int i = 0; i < m; i++) {
        Node* temp = head1;

        // Check if value exists in first list
        while (temp != NULL) {
            if (temp->data == arr2[i]) {
                intersectionNode = temp;
                break;
            }
            temp = temp->next;
        }

        if (intersectionNode != NULL) {
            if (head2 == NULL)
                head2 = intersectionNode;
            else {
                Node* t = head2;
                while (t->next != NULL)
                    t = t->next;
                t->next = intersectionNode;
            }
            break;
        } else {
            head2 = insertTail(head2, arr2[i]);
        }
    }

    Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}