/*
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

*/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        //add all character to a map
        unordered_map<char,int> mp;
        for (auto c : s) {
            mp[c]++;
        }
        
        //get first value in map to compare frequency
        int x = mp[s[0]];
        
        //loop through map and see if each frequency is the same
        for (auto it : mp) {
            if (it.second != x) {
                return false;
            }   
        }
        return true; 
    }        
    
};
