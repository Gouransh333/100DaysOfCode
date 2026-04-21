Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}

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
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, adjSize);
            count++;
        }
    }

    printf("%d", count);
    return 0;
}