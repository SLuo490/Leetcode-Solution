/*
Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
The tests are generated such that there is exactly one solution. You may not use the same element twice.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Binary Search
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum == target) {
                return {lo + 1, hi + 1}; //we are using 1 based index as result 
            } else if (sum < target) {
                lo++;
            } else {
                hi--;
            }
        }
        return {-1,-1}; //edge case where there is no answer
    }
};

/*
    [2,7,11,15] taret = 9
     -
       - 
    sum = 17 > 9
    lo = 0
    hi = 2
    
    sum = 13 > 9
    lo = 0
    hi = 1
    
    sum = 9 == 9
    lo = 0 + 1
    hi = 1 + 1
    
    return {1,2}
*/
