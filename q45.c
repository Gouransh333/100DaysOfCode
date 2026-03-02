roblem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50


#include <stdio.h>
#define MAX 1000  
struct Node {
    int data;
    int next; 
};
struct Node nodes[MAX];
int nodeCount = 0;
int createNode(int data) {
    nodes[nodeCount].data = data;
    nodes[nodeCount].next = -1;
    return nodeCount++;
}
int insertEnd(int head, int data) {
    int newNode = createNode(data);
    if (head == -1) return newNode;
     int temp = head;
    while (nodes[temp].next != -1) {
        temp = nodes[temp].next;
    }
    nodes[temp].next = newNode;
    return head;
}
int mergeLists(int list1, int list2) {
    if (list1 == -1) return list2;
    if (list2 == -1) return list1;

    int result;
    if (nodes[list1].data <= nodes[list2].data) {
        result = list1;
        nodes[result].next = mergeLists(nodes[list1].next, list2);
    } else {
        result = list2;
        nodes[result].next = mergeLists(list1, nodes[list2].next);
    }
    return result;
}
void printList(int head) {
    int temp = head;
    while (temp != -1) {
        printf("%d ", nodes[temp].data);
        temp = nodes[temp].next;
    }
}

int main() {
    int n, m, val, i;
    int list1 = -1, list2 = -1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }

  int mergedList = mergeLists(list1, list2);
    printList(mergedList);
    return 0;
}
