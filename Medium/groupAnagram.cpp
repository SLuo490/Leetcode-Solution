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

class Solution {
public:
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
};
