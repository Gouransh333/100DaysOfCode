Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED

#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int* visited, int** adj, int* adjSize) {
    visited[v] = 1;
    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            dfs(u, visited, adj, adjSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    dfs(1, visited, adj, adjSize);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}