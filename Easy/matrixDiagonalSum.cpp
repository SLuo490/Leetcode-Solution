/*
Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
*/


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, secondaryIdx = mat.size() - 1; 
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.size(); j++) {
                if (i == j || j == secondaryIdx) {
                    sum += mat[i][j]; 
                }
                
                if (j == secondaryIdx) {
                    secondaryIdx--; 
                }
            }
        }
        return sum; 
    }
};

/*

mat = [[1,2,3],
       [4,5,6],
       [7,8,9]]
       
         0  1  2
      0 11 12 13 
      1 21 22 23
      2 31 32 33

      [[1,1,1,1],
       [1,1,1,1],
       [1,1,1,1],
       [1,1,1,1]]
       
         0  1  2  3
     0  11 12 13 14
     1  21 22 23 24
     2  31 32 33 34
     3  41 42 43 44
     
     Secondary Diagonal: (0,3) (1,2) (2,1) (3,0)

      1) i == j then it is part of the diagonal
      2) secondary index = j.size - 1 to keep track of the secondary diagonal
         decrement secondary index once we added the diagonal
         
         once j == secondaryIndex then add the current index to sum then decrement secondary index
        
*/
