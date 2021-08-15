/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
*/


class Solution {
public:
    vector<int> getRow(int n) {
//         vector<int> currRow;
//         currRow.push_back(1);
//         if (n == 0) return currRow;

//         vector<int> prevRow = getRow(n - 1);
//         //calculates the row after 1
//         for (int i = 1; i < prevRow.size(); i++) {
//             int curr = prevRow[i-1] + prevRow[i];
//             currRow.push_back(curr);
//         }
//         //add 1 to the end of the row
//         currRow.push_back(1);

//         return currRow;
        
        //Dynamic Programming
        //fill res with 1s
        vector<int> res = vector<int>(n + 1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                res[j] += res[j-1];
            }
        }
        return res;
    }
};
