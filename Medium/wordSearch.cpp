/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return false; 
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0] && dfs(board, word, row, col, 0)) {
                    return true; 
                }
            }
        }
        return false; 
    }
    
    bool dfs (vector<vector<char>>& board, string word, int i, int j, int n) {
        if (n == word.size()) return true; 
        
        // if out of bound return false
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[n]) return false; 
        
        board[i][j] = '0';
        
        bool status = dfs(board, word, i + 1, j, n + 1) || 
                      dfs(board, word, i - 1, j, n + 1) || 
                      dfs(board, word, i, j + 1, n + 1) || 
                      dfs(board, word, i, j - 1, n + 1); 
        
        board[i][j] = word[n]; 
        
        return status; 
    }
};
