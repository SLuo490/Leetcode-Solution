/*
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

Example 1:
Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

Example 2:
Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
*/

// Brute Force
class Solution {
public:
    int countOdds(int low, int high) {
        int res = 0; 
        
        for (int i = low; i <= high; i++) {
            if (i % 2 != 0) {
                res++; 
            }
        }
        
        return res; 
    }
};

// More Optimal Solution
class Solution {
public:
    int countOdds(int low, int high) {
        int k = (high - low) / 2; 
        
        if (high % 2 != 0 || low % 2 != 0) {
            k += 1; 
        }
        return k;
    }
};
