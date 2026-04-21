There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

int dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next] && dfs(next, adj, adjSize, visited, recStack))
            return 1;
        else if (recStack[next])
            return 1;
    }

    recStack[node] = 0;
    return 0;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
     int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack))
                return false;
        }
    }

    return true;
}