/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //edge case, size == 0, return 0
        if (grid.size() == 0) {
            return 0; 
        }
        int maxArea = 0; 
        //traverse matrix, once we find a 1, dfs and find the max area
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, findMaxArea(grid, i, j)); 
                }
            }
        }
        
        return maxArea;
    }
    
    int findMaxArea(vector<vector<int>>& grid, int i, int j) {
        //base case
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) {
            return 0; 
        }
        
        //"sink" island so we don't revisit
        grid[i][j] = 0; 
        int count = 1; 
        
        //traverse matrix and updating count along the way
        count += findMaxArea(grid, i - 1, j); 
        count += findMaxArea(grid, i + 1, j); 
        count += findMaxArea(grid, i, j - 1); 
        count += findMaxArea(grid, i, j + 1); 

        return count; 
    }
};
