You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

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
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
struct Node** adj = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        struct Node* node = createNode(v, w);
        node->next = adj[u];
        adj[u] = node;
    }

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;

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
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            temp = temp->next;
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}