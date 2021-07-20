/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [1,1]
Output: 1
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         //O(n) Time and Space Complexity
//         unordered_map<int,int> mp;
        
//         //loop through nums and add to map
//         for (auto x : nums) {
//             mp[x]++;
//             if (mp[x] > 1) {
//                 return x;
//             }
//         }
//         return -1;
        
        //slow and fast at the number index 1
        int slow = nums[0];
        int fast = nums[0];
        
        //find the intersection (slow = fast)
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        //find the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        
        return slow;
    }
};
