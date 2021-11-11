/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
 
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //DP Bottom-Up Approach
        if (triangle.size() == 0) return 0; 
        //start at the bottom 
        vector<int> dp = triangle.back(); 
        for (int i = triangle.size() - 2; i >= 0; i--) { //last array - 1
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]); 
            }
        }
        return dp[0]; 
    }
};

/*



   [2]
  [3,4]
 [6,5,7]
[4,1,8,3]

   [2]
  [9,4]
 [7,6,10]
[4,1,8,3]



dp = [4,1,8,3]
i = 2
j = 0

dp[j] = triangl[i][j] + min(dp[j], dp[j + 1])
dp[0] = 6 + min(4,1)
dp[0] = 7

dp = [7,1,8,3]
i = 2
j = 1
dp[j] = triangl[i][j] + min(dp[j], dp[j + 1])
dp[1] = 5 + min(1,8)
dp[1] = 6

dp = [7,6,8,3]
i = 2
j = 2
dp[j] = triangl[i][j] + min(dp[j], dp[j + 1])
dp[2] = 7 + min(8,3)
dp[2] = 10


   [2]
  [3,4]
 [7,6,10]
 
dp = [9,10,10,3]

   [2]
  [9,10]

dp = [11,12,10,3]
return dp[0] = 11
*/
