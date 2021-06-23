/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Example 4:
Input: nums = [1,3,5,6], target = 0
Output: 0
 */




class Solution {
public:
    //[1,3,5,6]
    //size = 4
    //low = 0 (index)
    //high = 3 (index)
    //mid = 3 + 0  / 2 = 2 = 2
    int searchInsert(vector<int>& nums, int target) {
        //binary search
        int low = 0;
        int high = nums.size()-1;
        
        while (high >= low)
        {
            int middle = low + (high - low) /2;
            if (nums[middle] < target)
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
        
        return low;
    }
};
