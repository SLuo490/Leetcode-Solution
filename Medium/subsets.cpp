/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int start) {
        res.push_back(curr); 
        
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]); 
            backtrack(nums, res, curr, i + 1); 
            curr.pop_back(); 
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> curr; 
        
        backtrack(nums, res, curr, 0); 
        
        return res; 
    }
};
