/*
Given a set of n people (numbered 1, 2, ..., n), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

*/
const int UNVISITED = -1, COLORA = 0, COLORB = 1;

class Solution {
public:
    vector<vector<int>> graphs;
    bool isBipartition(int node, vector<int> &nodeStatus) {
        //use bfs approach to check wheher subgraph is bipartition
        bool is_bipartition = true;
        nodeStatus[node] = COLORA;
        queue<int> Q;
        Q.push(node);
        
        while (!Q.empty() && is_bipartition) {
            auto node = Q.front(); Q.pop();
            for (auto & neighbor : graphs[node]) {
                //neighbor is not visited
                if (nodeStatus[neighbor] == UNVISITED) {
                    //color neighbor a different color
                    nodeStatus[neighbor] = nodeStatus[node] == COLORA ? COLORB : COLORA;
                    Q.push(neighbor);
                } else if (nodeStatus[neighbor] == nodeStatus[node]) {
                        return false;
                }
            }
        }
        return true;
        
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //unvisited
        vector<int> nodeStatus(n+1, UNVISITED);
        
        //build the graph
        vector<vector<int>> graphs(n + 1);
        for (auto dislike : dislikes) {
            auto u = dislike[0], v = dislike[1];
            graphs[u].push_back(v);
            graphs[v].push_back(u);
        }
        
        this->graphs = graphs;
        
        for (int node = 1; node <= n; node++) {
            //if this node is not visited check the subgraph to see if it is bipartition
            if (nodeStatus[node] == UNVISITED) {
                if (!isBipartition(node, nodeStatus)) return false;
            }
        }
        
        return true;
        
    }
};
