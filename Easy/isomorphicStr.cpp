/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:
Input: s = "egg", t = "add"

Output: true
Example 2:
Input: s = "foo", t = "bar"

Output: false
Example 3:
Input: s = "paper", t = "title"

Output: true
*/


class Solution {
public:
    //Same Run Time
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
    
    
    /*
        map the character of s[i] to t[i] if s[i] is not in the map
        if s[i] is in the map, check if it is different from t[i]
        
        check for both (s,t) and (t,s)
    */
    bool helper (string s, string t) {
        unordered_map<char,char>mp;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i]) return false;
            } else {
                mp[s[i]] = t[i];
            }
        }
        return true; 
    }
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper (t,s);
    }
};








