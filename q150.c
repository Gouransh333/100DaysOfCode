Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-


// User function Template for C#

/*
class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
    }
};
*/

class Solution {
     int timer;

    void DFS(int u, int parent, int[] disc, int[] low, bool[] visited, List<int>[] adj, bool[] isAP) {
        visited[u] = true;
        disc[u] = low[u] = ++timer;
        int children = 0;

        foreach (int v in adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                children++;
                DFS(v, u, disc, low, visited, adj, isAP);

                low[u] = Math.Min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = true;
                }
            } else {
                low[u] = Math.Min(low[u], disc[v]);
            }
        }

        if (parent == -1 && children > 1) {
            isAP[u] = true;
        }
    }
    public List<int> articulationPoints(int V, List<int>[] adj) {
        
        int[] disc = new int[V];
        int[] low = new int[V];
        bool[] visited = new bool[V];
        bool[] isAP = new bool[V];

        timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, disc, low, visited, adj, isAP);
            }
        }

        List<int> result = new List<int>();
        for (int i = 0; i < V; i++) {
            if (isAP[i]) result.Add(i);
        }

        if (result.Count == 0) result.Add(-1);

        result.Sort();
        return result;
    }
}

