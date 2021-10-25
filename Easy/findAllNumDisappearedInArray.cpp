/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res; 
        //sort the array using cyclic sort
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                swap(nums[i], nums[nums[i] - 1]); 
                if (nums[i] == nums[nums[i] - 1]) {
                    break; 
                }
            }
        }
        
        //loop through sorted array and find missing num
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1); 
            }
        }
        return res;     
        
    }
};

/*
[4,2,3,4,8,2,3,8]
 1 2 3 4 5 6 7 8 


[1,2,3,4,3,2,7,8]
 1 2 3 4 5 6 7 8

[1,2,3,4,3,2,7,8]
 1 2 3 4 5 6 7 8 

[5,6]

1) after you swap, check to see if both index contain the same number
    If both index contains the same number, you want to break out loop
    
2) Loop through nums after sort and add the index where its num is different from idx to res


*/
