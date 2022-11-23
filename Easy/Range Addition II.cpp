#include <bits/stdc++.h>
using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    // edge cases: 
    if (ops.size() == 0) return m * n; 

    int minRow = INT_MAX; 
    int minCol = INT_MAX; 

    // simulate the ops
    for (int i = 0; i < ops.size(); i++) {
        // get the row and col to traverse through
        int row = ops[i][0]; 
        int col = ops[i][1]; 

        minRow = min(minRow, row); 
        minCol = min(minCol, col); 

    }
    return minRow * minCol; 
}

int main()
{
  return 0;
}