/*
You are given an integer array nums with the following properties:

- nums.length == 2 * n.
- nums contains n + 1 unique elements.
- Exactly one element of nums is repeated n times.

Return the element that is repeated n times.

Example 1:
Input: nums = [1,2,3,3]
Output: 3

Example 2:
Input: nums = [2,1,2,5,3,2]
Output: 2

Example 3:
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5

*/


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int N = nums.size(); 
        
        for (int i = 0; i < nums.size(); i++) {
            // use a map to keep track of the frequency of the character
            int num = nums[i]; 
            mp[num]++; 
            
            // if the frequency * 2 == length of nums then we have the N-repeated element
            if (mp[num] * 2 == N) {
                return num; 
            }
        }
        return 0; 
    }
};
