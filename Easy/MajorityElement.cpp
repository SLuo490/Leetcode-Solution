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
        //set the first element as the majority element
        int majorityCandidate = nums[0];
        int counter = 1;
        //loop through the rest of array
        for (int i = 1; i < nums.size(); i++) {
            if (counter == 0) {
                majorityCandidate = nums[i];
            }
            if (nums[i] == majorityCandidate) {
                counter++;
            }
            else {
                counter--;
            }

        }
        return majorityCandidate;
    }
    
};
