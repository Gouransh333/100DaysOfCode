There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>

int timer;

void dfs(int u, int parent, int* disc, int* low, int** adj, int* adjSize, int** result, int* returnSize, int* colSizes) {
    disc[u] = low[u] = ++timer;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize, colSizes);
            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                colSizes[*returnSize] = 2;
                (*returnSize)++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}
int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    int* colSizes = (int*)malloc(connectionsSize * sizeof(int));
    *returnSize = 0;

    timer = 0;
    dfs(0, -1, disc, low, adj, adjSize, result, returnSize, colSizes);

    *returnColumnSizes = colSizes;
    return result;
}