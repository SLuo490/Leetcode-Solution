#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int count = 0;
    int row = grid.size();
    int col = grid[0].size();

    // go through row - 3 and col - 3 and iterate through all possible
    // sub-grids
    for (int i = 0; i <= row - 3; i++) {
      for (int j = 0; j <= col - 3; j++) {
        if (isMagicSqu(grid, i, j)) {
          count++;
        }
      }
    }

    return count;
  }

  bool isMagicSqu(vector<vector<int>> &grid, int row, int col) {
    // check for distinct values from 1 - 9
    vector<bool> seen(10, false);
    // iterate through the grid starting at {row, col} up to 3x3
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int num = grid[row + i][col + j];
        if (num < 1 || num > 9)
          return false;
        if (seen[num])
          return false;
        seen[num] = true;
      }
    }

    // compute the sum for row, col, and diagonals
    int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
    int row2 =
        grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
    int row3 =
        grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];

    int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
    int col2 =
        grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
    int col3 =
        grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];

    int diag1 =
        grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
    int diag2 =
        grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

    return row1 == 15 && row2 == 15 && row3 == 15 && col1 == 15 && col2 == 15 &&
           col3 == 15 && diag1 == 15 && diag2 == 15;
  }
};

/*
    0,0 0,1 0,2
    1,0 1,1 1,2
    2,0 2,1 2,2
*/

int main() {
  Solution sol;
  vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  cout << sol.numMagicSquaresInside(grid) << endl;

  vector<vector<int>> grid2 = {{0}};
  cout << sol.numMagicSquaresInside(grid2) << endl;
}
