/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //edge case grid is 0
        if (grid.size() == 0) return 0;
        int num_island = 0;
        //loop through the 2d grid
        for (int i = 0; i < grid.size(); i++)
        {
            //grid[i].size is the number of element for the ith row of the grid 
            for (int j = 0; j < grid[i].size(); j++)
            {
                //if the grid i,j is '1', then do dfs and increment island
                if (grid[i][j] == '1')
                {
                    num_island++;
                    dfs(grid, i, j);
                }
            }
        }
        return num_island;
    }
    void dfs (vector<vector<char>>&grid, int i, int j)
    {
        //edge case: out of bound or grid is water '0'
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0')
        {
            return;
        }
        
        //set grid to water if it is land
        grid[i][j] = '0';
        //recursive dfs top,down,left,right
        dfs(grid,i-1,j); //top
        dfs(grid,i+1,j); //down
        dfs(grid,i,j-1); //left
        dfs(grid,i,j+1); //right

    }
};
