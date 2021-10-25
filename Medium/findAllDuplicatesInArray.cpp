/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []
*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res; 
        if (nums.size() == 1) return res; 
        
        //cyclic sort
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                swap(nums[i], nums[nums[i] - 1]); 
                if (nums[i] == nums[nums[i] - 1]) {
                    break; 
                }
            }
        }
        
        //loop through sorted nums
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]); 
            }
        }
        
        return res;     
    }
};

/*
[1,2,3,4,3,2,7,8]
 1 2 3 4 5 6 7 8 


[1,2,1]
 1 2 3


*/
