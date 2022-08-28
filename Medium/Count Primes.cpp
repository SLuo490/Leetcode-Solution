#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
*/

class Solution {
public:
    int countPrimes(int n) {
        // sieve of Eratosthenes algorithm
        vector<bool> prime (n + 1, true); 
        for (int p = 2; p * p < n; p++) {
            for (int i = p * p; i < n; i += p) {
                prime[i] = false; 
            } 
        }
        
        int res = 0; 
        for (int i = 2; i < n; i++) {
            if (prime[i]) res++; 
        }
        return res; 
    }
};

/*
    create a vector of boolean values up to n + 1 size
    set all the values to true
    
    traverse through the primes starting from 2, p * p <= n, p++
        if the current value is true then traverse through the vector and set all multiples of p to false
            for i = p * p; i <= n; i += p
                current value = false
    
    traverse through the vector and count how many value are true
*/

int main()
{
    return 0;
}