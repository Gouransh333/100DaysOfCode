Problem: Count Nodes in Linked List

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
    int next;  
};
int main() {
    int n;
    scanf("%d", &n);

    struct Node list[100];  
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i].data);
        list[i].next = (i == n - 1) ? -1 : i + 1;
    }
    int count = 0;
    int current = 0; 
    while (current != -1) {
        count++;
        current = list[current].next;
    }
    printf("%d\n", count);
    return 0;
}
