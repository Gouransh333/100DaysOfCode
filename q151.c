Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

void addEdge(struct Node** adj, int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, minDist = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}