#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.

Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:
Input: nums = [0]
Output: [0]

*/

class Solution {
public:
    // Brute Force
    // Time: O(N^2) Space: O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                continue; 
            }
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % 2 != 0) {
                    continue; 
                }
                
                swap(nums[i], nums[j]); 
                break; 
            }
        }
        return nums; 
    }

    // Optimal: Swapping In place
    // Time: O(N), space: O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] % 2 == 0) swap(nums[i++], nums[j]); 
        }
        return nums; 
    }

    /*
        [3, 1, 2, 4]
         -
         -
        
        nums[j] % 2 != 0, increment j

        [3, 1, 2, 4]
         -
            -
        
        nums[j] % 2 != 0, increment j


        [2, 1, 3, 4]
            -
                  -
        nums[j] % 2 == 0, swap j and j, and increment i

        [2, 4, 3, 1]
            -
                  -
        nums[j] % 2 == 0, swap j and j, and increment i
        end of loop
    */
};

int main()
{
    return 0;
}