/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

class Solution {
public:    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; 
        findPermutations(nums, res, 0); 
        return res; 
    }
    
    void findPermutations(vector<int>& nums, vector<vector<int>>& res, int idx) {
        //base case if idx == suze if nums then we found a permutation
        if (idx == nums.size()) {
            res.push_back(nums); 
            return;
        }

        //generate permutations
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]); 
            findPermutations(nums, res, idx + 1); 
            swap(nums[idx], nums[i]);
        }
    }
};
