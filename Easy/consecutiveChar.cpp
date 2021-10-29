/*
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.
Return the power of the string.
 
Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Example 3:
Input: s = "tourist"
Output: 1
*/

class Solution {
public:
    int maxPower(string s) {
        int length = 1, maxLength = 0; 
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[i + 1]) {
                length++; 
            } else {
                length = 1; 
            }
            maxLength = max(length, maxLength); 
        }
        return maxLength; 
    }
};

/*

"leetcode"
       -
        -
 count = 1
 maxChar = 2
*/
