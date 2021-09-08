/*
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:
Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

Example 2:
Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
*/

class Solution {
public:
    int searchPair(vector<int>& nums, int start, int target) {
        int right = nums.size() - 1;
        int left = start;
        int count = 0;
        
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                /*
                    KEY:
                    
                    If nums[left] + nums[right] < target, then there exists
                    number where nums[left] + nums[right - 1] < target
                    
                    count += right - left account for this logic
                */
                count += right - left; 
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
    
    
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return count; //Edge case: there are less than 2 item in nums
        for (int i = 0; i < nums.size() - 2; i++) {
            count += searchPair(nums, i + 1, target - nums[i]);
        }
        return count;
    }
};
