/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/


class Solution {
public:
    //O(n) Time and Space
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> res (n); 
        
        for (int i = 0; i < n; i++) {
            res[(i + k) % n] = nums[i]; //rotate array (MATH)
        }
        nums = res; 
    }
    
    //O(n) Time, O(1) Space
    void rotate(vector<int>& nums, int k) {        
        k = k % nums.size(); // we want modulo because k can be greater than n
        reverse(nums.begin(), nums.end()); //reverse entire array
        reverse(nums.begin(), nums.begin() + k); //reverse up to k 
        reverse(nums.begin() + k, nums.end()); //reverse k to end
    }
};

/*
[1,2,3,4,5]
 -           

k = 3, n = 5
(i + k) % n = 0 + 3 % 5 = 3

res[3] = nums[0]

[0,0,0,1,0]

-------------------------------
[1,2,3,4,5]

k = 3, n = 5
(i + k) % n = 1 + 3 % 5 = 4

res[4] = nums[1]

[0,0,0,1,2]

-------------------------------
[1,2,3,4,5]

k = 3, n = 5
(i + k) % n = 2 + 3 % 5 = 0

res[4] = nums[2]

[3,0,0,1,2]

...

*/
