/*
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
*/

// Brute Force:
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> mp; 
        for (auto ch : s1) {
            mp[ch]++; 
        }
        
        for (auto ch : s2) {
            if (mp.find(ch) != mp.end()) {
                mp[ch]--; 
                
                if (mp[ch] == 0) {
                    mp.erase(ch); 
                }
            }
        }
        
        if (mp.size() != 0) return false; 
        
        int count = 0; 
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) count++; 
            
            if (count > 2) return false; 
        }
        return true; 
    }
};

// Optimal:
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> mismatch; 
        // loop through string and emplace the position of mismatch into vector
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                mismatch.push_back(i); 
            }
        }
        
        if (mismatch.size() == 0) return true; 
        
        // if there are 2 mismatch, swap the character at its position
        if (mismatch.size() == 2) {
            swap(s1[mismatch[0]], s1[mismatch[1]]); 
        }
        
        return s1 == s2; 
    }
};
