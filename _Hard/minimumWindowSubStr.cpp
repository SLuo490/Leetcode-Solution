/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int windowStart = 0, minLength = s.length() + 1, subStrStart = 0, match = 0; 
        unordered_map<char,int> mp; 
        
        for (auto ch : t) {
            mp[ch]++;   
        } 
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char rightChar = s[windowEnd]; 
            if (mp.find(rightChar) != mp.end()) {
                mp[rightChar]--; 
                if (mp[rightChar] >= 0) {
                    match++; 
                }
            }
            
            while (match == t.length()) {
                if (minLength > windowEnd - windowStart + 1) {
                    minLength = windowEnd - windowStart + 1; 
                    subStrStart = windowStart; 
                }
                
                char leftChar = s[windowStart++]; 
                if (mp.find(leftChar) != mp.end()) {
                    if (mp[leftChar] == 0) {
                        match--; 
                    }
                    mp[leftChar]++; 
                }
            }
        }
        
        return minLength > s.length() ? "" : s.substr(subStrStart, minLength); 
    }
};
