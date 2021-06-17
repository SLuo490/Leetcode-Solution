/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2 
*/

class Solution {
public:
    /*
        [1,1,0,1,]
               - 
        count = 0
        maxOnes = 0
        ---------------
        i = 0
        count = 1
        maxOnes = max(1,0) = 1
        ---------------
        i = 1
        count = 2
        maxOnes = max(2,1) = 2
        ---------------
        i = 3
        count = 0
        maxOnes = max(0,2) = 2
        ---------------
        i = 4
        count = 1
        maxOnes = max(1,2) = 2
        return maxOnes // 2
    */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxOnes = 0;
        
        //loop through nums
        for (int i = 0; i < nums.size(); i++) {
            //if the number is a 1, increment count, and set maxOnes to the max of count and maxOnes
            if (nums[i] != 0) {
                count++;
                maxOnes = max(count, maxOnes);
            }
            //if the number is a 0, set count back to 0;
            else {
                count = 0;
            }
        }
        return maxOnes;
    }
};
