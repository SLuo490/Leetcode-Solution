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
        int maxChar = 0;
        int count = 1;

        int j = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[j]) {
                count++;
            } else {
                count = 1;
            }
            maxChar = max(count, maxChar);
            j++;
        }
        return maxChar;
    }
};

/*

"leetcode"
       -
        -
 count = 1
 maxChar = 2
*/
