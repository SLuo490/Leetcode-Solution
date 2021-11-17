/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/


class Solution {
public:
//     O(N) Time and Space
//     int minCostClimbingStairs(vector<int>& cost) {
//         if (cost.size() == 0) return 0; 
        
//         vector<int> dp (cost.size() + 1); 
        
//         for (int i = 2; i < dp.size(); i++) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); 
//         }
        
//         return dp[cost.size()]; 
//     }
    
/*
[1,10,1,1,1,10,1,1,10,1]
[0, 0,1,2,2, 3,3,4, 4,5, 6]
              -
dp[2] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
*/

    //O(n) Time and O(1) Space
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0; 
        int downTwo = 0; 
        
        for (int i = 2; i < cost.size() + 1; i++) {
            int temp = downOne; 
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]); 
            downTwo = temp; 
        }
        return downOne; 
    }
};
