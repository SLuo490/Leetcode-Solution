/*
You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.
For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.
An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.

Example 1:
Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].

Example 2:
Input: nums = [1,5,2,4,1]
Output: 14

Example 3:
Input: nums = [8]
Output: 0
*/

class Solution {
public:
    int minOperations(vector<int>& num) {
        int count = 0; 
        for (int i = 1; i < num.size(); i++) {
            if (num[i - 1] >= num[i]) {
                count += num[i - 1] - num[i] + 1; 
                num[i] += num[i - 1] - num[i] + 1; 
            } else if (num[i - 1] < num[i]) {
                continue; 
            }
        }
        return count; 
    }
};
/*
[1,5,6,7,1]

count = 0
5-2 = 3 + 1 = 4
count = 4

6 - 4 = 2 + 1 = 3
count = 7

7 - 1 + 1 = 7 
count = 14


[1,2,1]

count = 0
1 - 1 + 1 = 1
count = 1

2 - 1 + 1 = 2
count = 3


int count = 0
loop through the nums starting with 1
    if num[i - 1] > num[1] //not strictly increasing
        count += num[i - 1] - num[i] + 1 
        num[i] = num[i - 1] - num[i] + 1
    else num[i - 1] < num[i] 
        continue; 
    
*/
