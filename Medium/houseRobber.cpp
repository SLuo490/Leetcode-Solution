/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        //if there is zero house, you can only rob 0
        if (nums.size() == 0) return 0; 
        //if there is one house, you can only rob the first house
        if (nums.size() == 1) return nums[0]; 
        //if there is two house, rob the one with the max money
        if (nums.size() == 2) return max(nums[0], nums[1]); 
        
        //dynamic programming
        vector<int> dp (nums.size(), 0); 
        //one house
        dp[0] = nums[0]; 
        //two house
        dp[1] = max(nums[0], nums[1]); 
        
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max (nums[i] + dp[i - 2], dp[i - 1]); 
        }
        
        return dp[nums.size() - 1]; 
    }
    /*
        [1,2,3,1]
        
        dp[0] = 1
        dp[1] = max(1,2) = 2
        dp[1,2,0,0]
        
        i = 2
        
        dp[2] = max(nums[2] + dp[i - 2], dp[i - 1])
        dp[2] = max(3 + 1, 2)
        dp[2] = 4
        dp[1,2,4,0]
        
        i = 3
        dp[3] = max(nums[3] + dp[i - 2], dp[i - 1])
        dp[3] = max(1 + 2, 4)
        dp[3] = 4
        dp[1,2,4,4]
        
        return dp[nums.size() - 1] = 4
    */
};
