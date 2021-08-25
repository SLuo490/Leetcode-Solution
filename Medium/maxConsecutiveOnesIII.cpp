/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
  
Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int windowStart = 0, maxLength = 0, maxCountOnes = 0;
        unordered_map<int,int> mp;
        
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            //count the ones
            if (nums[windowEnd] == 1) {
                maxCountOnes++;
            }
            
            //we have the maximum allowed ones in array that are replaced with 1s,
            //if that maximum is past the allowed, k, then we need to move window
            if (windowEnd - windowStart + 1 - maxCountOnes > k) {
                if (nums[windowStart] == 1) {
                    maxCountOnes--;
                }
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};
