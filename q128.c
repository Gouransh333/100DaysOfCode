Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Node** adj, int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

void topoDFS(struct Node** adj, int v, int* visited, int* stack, int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            topoDFS(adj, temp->vertex, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(adj, i, visited, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}