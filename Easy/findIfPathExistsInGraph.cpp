/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex start to vertex end.
Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
  
Example 2:
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
*/

/* -------------------------------------  DFS  -----------------------------------------------------*/
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    //build the graph
    unordered_map<int, vector<int>>graph;
    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    //DFS
    //set visited to size n and all false
    vector<bool> visited(n,0);
    //add the start to stack 
    stack<int> st;
    st.push(start);
    visited[start] = 1;

    //traverse the graph
    while (!st.empty()) {
        //receive the top element of stack, if stack is the end return true
        auto top = st.top();
        if (top == end) return 1;
        st.pop();
        //traverse the vertices
        for (auto node : graph[top]) {
            //if node is not visited, add it to the visited and push it to stack
            if (!visited[node]) {
                visited[node] = 1;
                st.push(node);
            }
        }
    }
    return false;
}

/* -------------------------------------  Union Find  -----------------------------------------------------*/
//Faster than DFS
vector<int> root;
int find(int x) {
    if (x == root[x]) {
        return x;
    }
    return root[x] = find(root[x]);
}

void unionFind(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        root[rootX] = rootY;
    }
}

bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    //initialize root to itself
    root.resize(n);
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }

    //make graph
    for (auto e : edges) {
        unionFind(e[0], e[1]);
    }

    //check if start is connected to end
    return find(start) == find(end);
}









