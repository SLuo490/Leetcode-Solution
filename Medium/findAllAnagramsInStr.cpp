/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        
        int windowStart = 0, match = 0;
        
        //use hashmap to keep frequency of p
        unordered_map<char,int>mp;
        for (auto c : p) {
            mp[c]++;
        }
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            //if the right character is in map, then decrement the frequency in map and increment match
            char rightChar = s[windowEnd];
            if (mp.find(rightChar) != mp.end()) {
                mp[rightChar]--;
                if (mp[rightChar] == 0) {
                    match++;
                }
            }
            //if match is equal to the size of the map, then we have one anagram
            if (match == mp.size()) {
                result.push_back(windowStart);
            }
            
            //once the window reaches the length of p move the sliding window
            if (windowEnd >= p.length() - 1) {
                char leftChar = s[windowStart++];
                //if the left character is in the map and frequency is 0, decrement match since we are sliding the window
                if (mp.find(leftChar) != mp.end()) {
                    if (mp[leftChar] == 0) {
                        match--;
                    }
                    //reset the frequency of the left char for future window
                    mp[leftChar]++;
                }
            }
        }
        return result;
    }
};
