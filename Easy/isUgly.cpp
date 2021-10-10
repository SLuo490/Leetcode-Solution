/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number.

Example 1:
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: n = 8
Output: true
Explanation: 8 = 2 × 2 × 2

Example 3:
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

Example 4:
Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
*/

class Solution {
public:
    bool isUgly(int n) {
        //Slow: O(n) time
        // vector<int> primes = {2,3,5};
        // if (n < 1) return false;
        // for (int p : primes) {
        //     while (n % p == 0) {
        //         n/=p;
        //     }
        // }
        // return n == 1;
        
        if (n < 1) return false;
        // loop through the numbers 2,3,4,5
        for (int i = 2; i < 6; i++) {
            while (n % i == 0) {
                n/=i;
            }
        }
        return n == 1;
    }
};
