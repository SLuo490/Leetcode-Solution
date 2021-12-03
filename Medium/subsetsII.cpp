/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/


class Solution {
public:
    void backtrack (vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int start) {
        res.push_back(curr); 
        
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i - 1]) { // check if there is duplicates
                curr.push_back(nums[i]); 
                backtrack(nums, res, curr, i + 1); 
                curr.pop_back();    
            }
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> res; 
        vector<int> curr; 
        
        backtrack(nums, res, curr, 0); 
        
        return res; 
    }
};
