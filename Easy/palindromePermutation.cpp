/*
Given a string s, return true if a permutation of the string could form a palindrome.

Example 1:
Input: s = "code"
Output: false

Example 2:
Input: s = "aab"
Output: true

Example 3:
Input: s = "carerac"
Output: true
*/


class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> mp; 
        for (auto ch : s) {
            mp[ch]++; 
        }
        
        int count = 0; 
        for (auto it = mp.begin(); it!=mp.end(); it++) {
            if (it->second % 2 != 0) {
                count++; 
            }
        }
        return count <= 1; 
    }
};

/*

What makes a palindrome:

* if count is less than 2, then we can make a palindrome with permutation

racecar

2:r
2:a
2:c
1:e

mp[r] % 2 == 0
mp[a] % 2 == 0
mp[c] % 2 == 0
mp[e] % 2 != 0 -> count++; 

count <= 1 -> true 


code
c:1
o:1
d:1
e:1

count == 4


aab

a: 2
b: 1

mp[a] % 2 == 0
mp[b] % 2 == 1 count++

count == 1 -> true


*/
