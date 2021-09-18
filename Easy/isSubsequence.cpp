/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Two pointer approach
        int left = s.length(), right = t.length();
        int i = 0, j = 0;
        
        //loop until either i or j is less than its string length
        //if the character i and j is equal, then increment i 
        while (i < left && j < right) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        
        //if i is equal to the length of s, then s is a subsequence of t
        return i == left;
    }
};

/*
s = "abc"
t = "ahbdc"


"abc"
 -
"ahbdc"
 -

a == a => increment i and j

"abc"
  -
"ahbdc"
  -

b != h => increment j

"abc"
  -
"ahbdc"
   -

b == b => increment i and j

"abc"
   -
"ahbdc"
    -
    
...


"abc"
   -
"ahbdc"
     - 

c == c => increment i and j => end of loop

i == length of s, so it is true

*/
