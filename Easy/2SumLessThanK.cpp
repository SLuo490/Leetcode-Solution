/*
Given an array nums of integers and integer k, return the maximum sum such that there exists i < j with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.

Example 1:
Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

Example 2:
Input: nums = [10,20,30], k = 15
Output: -1
Explanation: In this case it is not possible to get a pair sum less that 15.
*/


class Solution {
public:
    
    // O(n^2) Slow
    // int twoSumLessThanK(vector<int>& nums, int k) {
    //     int sum = -1;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] + nums[j] < k) {
    //                 sum = max(sum, nums[i] + nums[j]);
    //             }
    //         }
    //     }
    //     return sum;
    // }
    
    //O(nLogN)
    int twoSumLessThanK(vector<int>& nums, int k) {
        int sum = -1;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int currSum = nums[left] + nums[right];
            if (currSum < k) {
                sum = max(sum, currSum);
                left++;
            } else {
                right--;
            }
        }
        return sum;
    }
};
