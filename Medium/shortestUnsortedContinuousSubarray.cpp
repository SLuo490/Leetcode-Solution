/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0
*/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = 0, hi = nums.size() - 1; 
        
        // find the first unsorted lo position
        while (low < nums.size() - 1 && nums[low] <= nums[low + 1]) {
            low++; 
        }
        
        // already sorted
        if (low == nums.size() - 1) {
            return 0; 
        }
        
        // find the first unsorted hi position
        while (hi > 0 && nums[hi] >= nums[hi - 1]) {
            hi--; 
        }
        
        // find the maximum and minimum in current subarray
        int maxSub = INT_MIN, minSub = INT_MAX; 
        for (int i = low; i <= hi; i++) {
            maxSub = max(maxSub, nums[i]); 
            minSub = min(minSub, nums[i]); 
        }
        
        // extend low backwards
        while (low > 0 && nums[low - 1] > minSub) {
            low--; 
        }
        
        // extend hi backwards
        while (hi < nums.size() - 1 && nums[hi + 1] < maxSub) {
            hi++; 
        }
        
        return hi - low + 1; 
    }
};

/*
    [1, 3, 2, 0, -1, 7, 10]
                         
    1) Find the first unsorted lo and hi
    
    2) find the maxSub and minSub
    
    3) extend lo and hi backward by comparing it to min and max

    4) return hi - lo + 1
*/
