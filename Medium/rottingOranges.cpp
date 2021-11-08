/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(); 
        if (row == 0) return 0; 
        int col = grid[0].size(); 
        
        //traverse grid and calculate number of fresh orangees and enqueue rotten oranges to queue
        queue<pair<int,int>> q; 
        int fresh = 0; 
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    fresh++; 
                } else if (grid[i][j] == 2) {
                    q.push({i,j}); 
                }
            }
        }
        
        //neighbor directions {left, right, down, up}
        int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; 
        int minutes = -1; 
        
        //traverse the queue
        while (!q.empty()) {
            int level = q.size(); 
            while (level--) {
                pair<int,int> curr = q.front(); 
                q.pop(); 
                
                //traverse the current node's 4 direction 
                for (int i = 0; i < 4; i++) {
                    // if the newR and newC is a fresh orange, update the orange to rotten and push {newR, newC} to queue and decrement fresh
                    int newR = curr.first + dir[i][0], newC = curr.second + dir[i][1]; 
                    if (newR >= 0 && newC >= 0 && newR < row && newC < col && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2; 
                        q.push({newR, newC}); 
                        fresh--; 
                    }                                                                                
                }
            }
            minutes++; 
        }
        //if there is fresh orange, return -1
        if (fresh > 0) return -1; 
        //if there are no oranges, return 0; 
        if (minutes == - 1) return 0; 
        return minutes; 
    }
};

/*
count = 1

[[2,2,1]
 [2,1,0]
 [0,1,1]]

count = 2
 
[[2,2,2]
 [2,2,0]
 [0,1,1]]

count = 3

[[2,2,2]
 [2,2,0]
 [0,2,1]]

count = 4

[[2,2,2]
 [2,2,0]
 [0,2,2]]
*/
