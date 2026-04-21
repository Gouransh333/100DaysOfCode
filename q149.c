Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** cost = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        cost[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }

    int* key = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0;
    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
            }
        }
    }

    printf("%d", total);
    return 0;
}