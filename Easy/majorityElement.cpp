/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

//[2,2,1,1,1,2,2]
//   -
//majority element = 2
//counter = 1
//i = 1

//[2,2,1,1,1,2,2]
//   -
//majority element = 2
//counter = 2
//i = 2

//[2,2,1,1,1,2,2]
//     -
//majority element = 2
//counter = 1
//i = 3

//[2,2,1,1,1,2,2]
//       -
//majority element = 2
//counter = 0
//i = 4

//[2,2,1,1,1,2,2]
//         -
//majority element = 1
//counter = 1
//i = 5

//[2,2,1,1,1,2,2]
//           -
//majority element = 1
//counter = 0
//i = 6

//[2,2,1,1,1,2,2]
//             -
//majority element = 2
//counter = 1
//i = 6

//returns 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int counter = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (counter == 0) {
                majority = nums[i];
            }
            if (majority == nums[i]) {
                counter++;
            } else {
                counter--;
            }
        }
        return majority;
        
        // //map (SLOW)
        // unordered_map<int,int> mp;
        // for (int num : nums) {
        //     mp[num]++;
        //     //We can use the fact that the majority element is the element that appears more than n/2 times
        //     if (mp[num] > nums.size() / 2) {
        //         //if the num appears more than n/2 times, return num
        //         return num;
        //     }
        // }
        // return 0;            
        
    }
};
