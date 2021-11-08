/*
You are given an m x n grid rooms initialized with these three possible values.

- -1 A wall or an obstacle.
- 0 A gate.
- INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

 
Example 1:
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

Example 2:
Input: rooms = [[-1]]
Output: [[-1]]

Example 3:
Input: rooms = [[2147483647]]
Output: [[2147483647]]

Example 4:
Input: rooms = [[0]]
Output: [[0]]
*/


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size(); 
        if (row == 0) return;
        int col = rooms[0].size(); 
        
        // add all gates(0) to queue
        queue<pair<int,int>> q; 
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i,j}); 
                }
            }
        }
      
        //neighbor directions {left, right, down, up}
        int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; 
        
        //traverse the queue
        while (!q.empty()) {
            pair<int,int> curr = q.front(); 
            q.pop(); 
          
            //traverse the current node's 4 direction 
            for (int i = 0; i < 4; i++) {
                // If the newR and newC is within the ranges of the room and a valid path(INT_MAX), then update the distance from gate and push newR and newC
                int newR = curr.first + dir[i][0], newC = curr.second + dir[i][1]; 
                if (newR >= 0 && newC >= 0 && newR < row && newC < col && rooms[newR][newC] == INT_MAX) {
                    rooms[newR][newC] = rooms[curr.first][curr.second] + 1; 
                    q.push({newR, newC}); 
                }
            }
        }
    }
};
