/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res; 
        //cyclic sort
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                swap(nums[i], nums[nums[i] - 1]); 
                if (nums[i] == nums[nums[i] - 1]) break;
            }
        }
        
        //loop through the list, if there is a mismatch btw index and element, then we found the repetition and loss of another
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return {nums[i], i + 1};
            }
        }
        
        
        return res; 
    }
};

/*

[1, 2, 3, 2, 5]
 1  2  3  4  5
 
 [2,4]
 
[1, 2, 3, 4, 3, 6]
 1  2  3  4  5  6
 
 [3,5]
 
*/
