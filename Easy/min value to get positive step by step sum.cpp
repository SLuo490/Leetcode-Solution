#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums, you start with an initial positive value startValue.
In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
Return the minimum positive value of startValue such that the step by step sum is never less than 1.

Example 1:
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
step by step sum
startValue = 4 | startValue = 5 | nums
  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
  (4 +2 ) = 6  | (5 +2 ) = 7    |   2

Example 2:
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 
*/

class Solution {
public:
    // Brute Force
    int minStartValue(vector<int>& nums) {
        int startVal = 1; 
        
        while (true) {
            int total = startVal; 
            bool valid = true; 
            
            for (int num : nums) {
                total += num; 
                
                // if total is less than one set valid to false and break
                if (total < 1) {
                    valid = false; 
                    break; 
                }
            }
            
            // if valid is true return the start value else increment start value for next iteration
            if (valid) {
                return startVal; 
            } else {
                startVal++; 
            }
        }
        return -1; 
    }

    // binary search method
    int minStartValue(vector<int>& nums) {
        int n = nums.size(); 
        int m = 100; 
        
        int left = 1, right = n * m + 1; 
        
        while (left < right) {
            int middle = left + (right - left) / 2; 
            int total = middle; 
            bool valid = true; 
            
            for (int num : nums) {
                total += num; 
                
                if (total < 1) {
                    valid = false; 
                    break; 
                }
            }
            
            if (valid) {
                right = middle; 
            } else {
                left = middle + 1; 
            }
        }
        return left; 
    }
};

int main()
{
  return 0;
}