/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

Example 3:
Input: graph = [[1],[]]
Output: [[0,1]]

Example 4:
Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]

Example 5:
Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
*/

class Solution {
public:
    void dfs(vector<vector<int>>&graph, vector<vector<int>>&paths, vector<int>& path, int node) {
        path.push_back(node);
        //once you reached the end of the graph, push the path to paths
        if (node == graph.size() - 1) {
            paths.push_back(path);
        } else {
            //traverse the current node
            for (auto it : graph[node]) {
                dfs(graph, paths, path, it);
            }
        }
        path.pop_back();
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //result of different paths
        vector<vector<int>> paths;
        //save different path to paths
        vector<int> path;
        //traverse the graph (DFS)
        dfs(graph, paths, path, 0); //start with 0 because it is the vertex (e.g [1,2] => 0 connects to 1 and 2)
        
        //return all the paths
        return paths;
    }
};




