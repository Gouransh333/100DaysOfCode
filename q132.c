Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

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

struct Pair {
    int vertex, dist;
};

void swap(struct Pair* a, struct Pair* b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Pair heap[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && heap[l].dist < heap[smallest].dist) smallest = l;
    if (r < n && heap[r].dist < heap[smallest].dist) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

struct Pair extractMin(struct Pair heap[], int* size) {
    struct Pair root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

void insertHeap(struct Pair heap[], int* size, struct Pair val) {
    int i = (*size)++;
    heap[i] = val;

    while (i && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    struct Pair* heap = (struct Pair*)malloc(n * n * sizeof(struct Pair));
    int size = 0;

    insertHeap(heap, &size, (struct Pair){src, 0});

    while (size > 0) {
        struct Pair curr = extractMin(heap, &size);
        int u = curr.vertex;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(heap, &size, (struct Pair){v, dist[v]});
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}