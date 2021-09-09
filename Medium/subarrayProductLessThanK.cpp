/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
*/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //edge case
        if (k <= 1) return 0;
      
        int product = 1;
        int windowStart = 0;
        int ans = 0;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            //start window
            product *= nums[windowEnd];
            
            //if the product of window is past target, then we need to calculate the window length
            while (product >= k) {
                //divide by the first num and increment windowstart
                product /= nums[windowStart++];
            }
            //increment ans by the length of window
            ans += windowEnd - windowStart + 1;
        }
        return ans;
    }
};
