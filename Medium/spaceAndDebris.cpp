#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std; 

/*
You are given a matrix that represents space where ‘O’ represents a path and ‘-’ represents a debris. You start off at position {0,0} and want to reach the end of the matrix. Return true if there is a path from the starting position to the ending position

Input: matrix: 

O O O O O 
- - - - O
- - - - O
- - - - O

Output: True

=======Follow Up:========

Find the shortest path from source to end 

Input: matrix: 

O O S O O 
- - O - O
- - O - O
- - E - O

Output: 2
*/

bool isValidPath(vector<vector<char>>& grid) {
    //init row, col, visited, queue, and 4 directions to traverse
    int row = grid.size(), col = grid[0].size(); 
    vector<vector<bool>> visited(row, vector(col, false)); 
    queue<pair<int,int>> q; 
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 

    // push the start direction to queue and mark it as visited
    q.push({0,0}); 
    visited[0][0] = true; 

    // start bfs traversal
    while (!q.empty()) {
        pair<int,int> curr = q.front(); 
        q.pop(); 

        // check if current position is at the end of the matrix, return true if it is
        if (curr.first == row - 1 && curr.second == col - 1) return true; 

        // check the 4 cardinal directions 
        for (int i = 0; i < 4; i++) {
            int newRow = curr.first + dir[i][0], newCol = curr.second + dir[i][1]; 

            // if newRow and newCol is within bound, not visited, and is O make new row and new col as visited and push it to queue
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !visited[newRow][newCol] && grid[newRow][newCol] == '0') {
                visited[newRow][newCol] = true; 
                q.push({newRow, newCol}); 
            }
        }
    }
    return false; 
}

int main() {
    vector<vector<char>> grid = 
    {
        {'0','0','0','0','0'},
        {'-','-','-','0','0'},
        {'-','-','-','0','0'},
        {'-','-','-','0','-'},
        {'-','-','-','0','0'}
    };
    cout << isValidPath(grid) << endl;

    return 0; 
}