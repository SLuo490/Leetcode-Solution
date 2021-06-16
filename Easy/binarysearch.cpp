/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        //edge case
        if (nums.size() == 0) return -1;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int middle = low + (high - low) / 2;
            //once the middle element is equal to target, return the middle index
            if (nums[middle] == target)
            {
                return middle;
            }
            //update low if the target is greater than middle
            else if (nums[middle] <= target)
            {
                low = middle + 1;
            }
            //update high if the target is less than middle
            else
            {
                high = middle - 1;
            }
        }
        //return -1 if there is no target in nums
        return -1;
    }
};
