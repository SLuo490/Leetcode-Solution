/*
Write an afficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(); 
        int col = matrix[0].size(); 
        
        int lo = 0, hi = row * col - 1; 
                        
        while (lo != hi) {
            int mid = lo + (hi - lo) / 2; 
            // matrix[mid / col][mid % col] -> the middle element in matrix
            if (matrix[mid/col][mid % col] < target) {
                lo = mid + 1; 
            } else {
                hi = mid; 
            } 
        }
        return matrix[hi/col][hi % col] == target; 
    }
};
