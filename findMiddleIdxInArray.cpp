/*
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).
A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].
If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.
Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

Example 1:
Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4

Example 2:
Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0

Example 3:
Input: nums = [2,5]
Output: -1
Explanation: There is no valid middleIndex.
*/

#include <iostream>
#include <vector>

using namespace std; 

// Time Complexity: O(K * (NM)) ??
// Space : O(1)
int findMiddleIndex(vector<int>& nums) {
    int leftMostSum = 0, rightMostSum = 0; 
    
    // O(K) --> length of nums
    for (int i = 0; i < nums.size(); i++) {
        leftMostSum = 0; 
        rightMostSum = 0; 
        
        // O(N)
        // calculate leftmost sum
        for (int j = 0; j < i; j++) {
            leftMostSum += nums[j]; 
        }

        // O(M)
        // calculate rightmost sum
        for (int k = nums.size() - 1; k > i; k--) {
            rightMostSum += nums[k]; 
        }
        
        if (i == 0) leftMostSum = 0; 
        if (i == nums.size() - 1) rightMostSum = 0; 
        
        if (leftMostSum == rightMostSum) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    vector<int> nums = {2,3,-1,8,4}; 
    cout << findMiddleIndex(nums) << endl;

    return 0; 
}