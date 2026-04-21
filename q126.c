Problem: Detect cycle in directed graph using DFS and recursion stack. Output: - YES if cycle exists

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

int dfs(struct Node** adj, int v, int* visited, int* recStack) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u] && dfs(adj, u, visited, recStack))
            return 1;
        else if (recStack[u])
            return 1;
        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
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
    int* recStack = (int*)calloc(n, sizeof(int));

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, visited, recStack)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}