Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.

class Solution {
     bool dfs(int node, int parent, bool[] visited, List<int>[] adj) {
        visited[node] = true;

        foreach (int neighbor in adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited, adj))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    public bool isCycle(int V, int[,] edges) {
         List<int>[] adj = new List<int>[V];
        for (int i = 0; i < V; i++)
            adj[i] = new List<int>();

        int E = edges.GetLength(0);
        for (int i = 0; i < E; i++) {
            int u = edges[i, 0];
            int v = edges[i, 1];
            adj[u].Add(v);
            adj[v].Add(u);
        }

        bool[] visited = new bool[V];

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited, adj))
                    return true;
            }
        }

        return false;
    }
        
    }
