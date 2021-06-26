/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        //sliding window
        int left = 0, right = 0;
        int res = 0;
        unordered_map <char,int> window;
    
        while (right < s.length()) {
            char c = s[right];
            //add character to window
            window[c]++;
            //increment right (next character)
            right++;
            
            //if there is repeating character, delete the character in map and increment left
            while (window[c] > 1) {
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            //set res to the max window
            res = max(res, right-left);
        }
        return res;
    }
};
