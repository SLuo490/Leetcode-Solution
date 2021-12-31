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

// Time Complexity: O(N + M) where N and M is the length of the string 
// Space Complexity: O(M) where M is the map of the pattern
class Solution {
public:
    string minWindow(string s, string t) {
        int minLength = INT_MAX, match = 0, subStrStart = 0; 
        int windowStart = 0; 
        unordered_map<char, int> mp; 
        
        // add each character in t to map
        for (auto ch : t) {
            mp[ch]++; 
        }
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            // if current character is in map, then decrement its frequency
            char rightChar = s[windowEnd]; 
            if (mp.find(rightChar) != mp.end()) {
                mp[rightChar]--; 
                // count every matching of a character
                if (mp[rightChar] >= 0) {
                    match++; 
                }
            }
            
            while (match == t.length()) {
                // keep track of the length
                if (minLength > windowEnd - windowStart + 1) {
                    minLength = windowEnd - windowStart + 1; 
                    subStrStart = windowStart; 
                } 
                
                // break out loop once there is no more redunctant character going out
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
