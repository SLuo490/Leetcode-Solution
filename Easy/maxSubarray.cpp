/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
*/

//Dynamic Programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //set currMax and sumMax to the first number
        int currMax = nums[0];
        int sumMax = nums[0];
        
        
        //loop through the num starting at 1
        for (int i = 1; i < nums.size(); i++) {
            //if the currMax is negative, throw it away, else keep adding to the currMax
            currMax = max(nums[i], currMax + nums[i]);
            //set sumMax to the max of currMax and sumMax
            sumMax = max(sumMax, currMax);
        }
        return sumMax;
    }
};

/*
[-2,1,-3,4,-1,2,1,-5,4]
                -
currMax = -2
sumMax = -2

---

currMax = max(1, -2 + 1) => 1
sumMax = max(-2, 1) => 1

---

currMax = max (-3, 1 + -3) => -2
sumMax = max(1, -2) => 1

---

currMax = max(4, -2 + 4) => 4
sumMax = max(1,4)) => 4

---

currMax = max(-1, 4 + -1) => 3
sumMax = max(4, 3) = 4

---

currMax = max(2, 3 + 2) => 5
sumMax = max(4,5) = 5

---

currMax = max(1, 5 + 1) => 6
sumMax = max(5,6) => 6

...

*/
