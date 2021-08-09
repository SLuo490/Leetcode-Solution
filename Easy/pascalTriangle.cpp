/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        
        //loop through the number of rows
        for (int i = 0; i < numRows; i++) {
            //fill the row with 1s
            vector<int> row (i + 1, 1);
            for (int j = 1; j < i; j++) {
                //this calculates the next row by updating the 1s in row
                row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		    }
            //push back the rows to res
		    ret.push_back(row);      
        }
        return ret;
    }
};
