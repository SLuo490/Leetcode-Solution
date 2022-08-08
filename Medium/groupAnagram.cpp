/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
*/

// Time Complexity: O(m * n log n)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    // Time: O(m * nlogn)
    // Space: O(n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; 
        for (string s : strs) {
            string key = s; 
            sort(key.begin(), key.end()); 
            mp[key].push_back(s); 
        }
        
        vector<vector<string>> res; 
        for (auto m : mp) {
            res.push_back(m.second); 
        }
        return res; 
    }

    // Optimal Solution
    // Time: O(m * n * 26)
    // Space: O(m * n * 26) 
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        vector<vector<string>> res; 
        unordered_map<string, vector<string>> mp; 

        // traverse through the strs
        for (string s : strs) {
            // convert string s to key
            string key = getKey(s); 
            mp[key].push_back(s); 
        }

        for (auto it : mp) {
            res.push_back(it.second); 
        }
        return res; 
    }

    // count the frequency of the characters in string s and make it into a string
    /*
        string s = "abc"
        count = 11100000...00 -> 0 -> a, 1 -> b, 2 -> c
        key = 98 98 98 97 97 ... 97 97
    */
    string getKey (string s) {
        string key = ""; 
        vector<int> count(26); 
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; 
        }

        for (int i = 0; i < 26; i++) {
            key += to_string(count[i] + 'a'); 
        }
        return key; 
    }
};
