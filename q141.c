In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int* rank, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py) return;

    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    int* rank = (int*)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++) parent[i] = i;

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(parent, u) == find(parent, v)) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(parent, rank, u, v);
        }
    }

    *returnSize = 2;
    return result;
}