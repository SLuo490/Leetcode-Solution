/*
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
Return the number of connected components in the graph.

Example 1:
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
*/

class Solution {
public:
    void dfs(vector<int> adjList[], vector<int>& visited, int src) {
        visited[src] = 1;
        
        for (int i = 0; i < adjList[src].size(); i++) {
            if (visited[adjList[src][i]] == 0) {
                dfs(adjList, visited, adjList[src][i]); 
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0; 
        
        int res = 0; 
        //initialize visited and adjlist
        vector<int> visited (n, 0); 
        vector<int> adjList[n]; 
        
        // create Adjacent list
        for (int i = 0; i < edges.size(); i++) {
            int start = edges[i][0]; 
            int end = edges[i][1]; 
            
            adjList[start].push_back(end); 
            adjList[end].push_back(start); 
        }
        
        // traverse the graph and if not visited, bfs
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                res++; 
                dfs(adjList, visited, i); 
            }
        }
        return res; 
    }
};
