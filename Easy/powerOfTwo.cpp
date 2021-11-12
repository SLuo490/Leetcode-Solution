/*
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false

Example 4:
Input: n = 4
Output: true

Example 5:
Input: n = 5
Output: false
*/


class Solution {
public:
//     Iterative Solution O(log n)
//     bool isPowerOfTwo(int n) {
//         if (n == 0) return false; 
        
//         while (n % 2 == 0) n /= 2; 
        
//         return (n == 1);
//     }
    
    // O(1) Time and Space Complexity
    bool isPowerOfTwo(int n) {
        if (n == 0) return false; 
        
        long x = n; 
        
        return (x & (x - 1)) == 0; 
    }
    
    /*
        n = 4       0 0 0 0 0 1 0 0
        n - 1       0 0 0 0 0 0 1 1 // -1 change rightmost 1-bit to 0 and set all lower bit to 1
        
     x & (x - 1))   0 0 0 0 0 0 0 0 // and operator: set the rightmost 1-bit to zero
        
        (x & (x - 1)) == 0 return true
    
        
        n = 6       0 0 0 0 0 1 1 0
        n - 1       0 0 0 0 0 1 0 1
        
     x & (x - 1))   0 0 0 0 0 1 0 0 
     
        (x & (x - 1)) != 0 return false
    */
};
