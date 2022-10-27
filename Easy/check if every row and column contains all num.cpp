#include <bits/stdc++.h>
using namespace std;

/*
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

Example 1:
Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

Example 2:
Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.
*/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            // one set to check row
            set<int> s1; 
            // one set to check col
            set<int> s2; 
            for (int j = 0; j < matrix.size(); j++) {
                // if s1 or s2 finds a duplicate (contain in set) return false
                if (s1.find(matrix[i][j]) != s1.end() || s2.find(matrix[j][i]) != s2.end()) {
                    return false; 
                }
                // add the number from row and col to s1 and s2 repectively 
                s1.insert(matrix[i][j]); 
                s2.insert(matrix[j][i]); 
            }
        }
        return true; 
    }
};

int main()
{
  return 0;
}