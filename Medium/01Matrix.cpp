/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

class Solution {
public:
    //Dynamic Programming O(r * c) Time, O(1) Space
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
    
    //Queue Implementation O(r * c) Time and Space
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(); 
        if (row == 0) return mat; 
        int col = mat[0].size(); 
        
        //distance vector
        vector<vector<int>> dist(row, vector<int> (col, INT_MAX)); 
        queue<pair<int,int>> q; 
        
        //add all zeros into distance
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0; 
                    q.push({i,j}); // push all zero into queue with its position
                }
            }
        }
        
        //neighbor direction (left, right, down, up)
        int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; 
        
        //traverse the queue
        while (!q.empty()) {
            pair<int,int> curr = q.front(); 
            q.pop(); 
            
            //traverse the current node's 4 direction
            for (int i = 0; i < 4; i++) {
                
                //If the new calculated neighbor {newr, newC} is smaller, we add {newR, newC}
                //to the queue and update dist[newR][newC]
                int newR = curr.first + dir[i][0], newC = curr.second + dir[i][1];
                if (newR >= 0 && newC >= 0 && newR < row && newC < col) {
                    if (dist[newR][newC] > dist[curr.first][curr.second] + 1) {
                        dist[newR][newC] = dist[curr.first][curr.second] + 1; 
                        q.push({newR, newC}); 
                    }
                }
            }
        }
        
        return dist; 
    }
};

/*
[[0,1,2]
 [1,2,3]
 [2,3,4]]

Return the matrix with the nearest distance from the 0th cell 

[[0,1,2],
 [1,2,3],
 [2,3,4]]

*/
