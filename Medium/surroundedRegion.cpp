/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:
Input: board = [["X"]]
Output: [["X"]]
*/


class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        //edge case: skip 'X'
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') {
            return; 
        }
        
        board[i][j] = 'T'; 
        
        dfs(board, i + 1, j); 
        dfs(board, i - 1, j); 
        dfs(board, i, j + 1); 
        dfs(board, i, j - 1); 
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size(); 
        
        // row border
        for (int i = 0; i < row; i++) {
            dfs(board, i, 0); 
            dfs(board, i, col - 1); 
        }
        
        //col border
        for (int i = 0; i < col; i++) {
            dfs(board, 0, i); 
            dfs(board, row-1, i); 
        }
        
        // traverse the matrix: O->X, T->O
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; 
                if (board[i][j] == 'T') board[i][j] = 'O'; 
            }
        }
    }
};
