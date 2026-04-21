Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 class Solution {
    void dfs1(int u, bool[] visited, List<int>[] adj, Stack<int> st) {
        visited[u] = true;
        foreach (int v in adj[u]) {
            if (!visited[v]) {
                dfs1(v, visited, adj, st);
            }
        }
        st.Push(u);
    }

    void dfs2(int u, bool[] visited, List<int>[] transpose) {
        visited[u] = true;
        foreach (int v in transpose[u]) {
            if (!visited[v]) {
                dfs2(v, visited, transpose);
            }
        }
    }

    public int kosaraju(int V, List<Tuple<int, int>> edges) {
        List<int>[] adj = new List<int>[V];
        List<int>[] transpose = new List<int>[V];

        for (int i = 0; i < V; i++) {
            adj[i] = new List<int>();
            transpose[i] = new List<int>();
        }

        foreach (var edge in edges) {
            int u = edge.Item1;
            int v = edge.Item2;
            adj[u].Add(v);
            transpose[v].Add(u);
        }

        bool[] visited = new bool[V];
        Stack<int> st = new Stack<int>();

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, visited, adj, st);
            }
        }

        for (int i = 0; i < V; i++) visited[i] = false;

        int count = 0;

        while (st.Count > 0) {
            int node = st.Pop();
            if (!visited[node]) {
                dfs2(node, visited, transpose);
                count++;
            }
        }

        return count;
        
    }
}
