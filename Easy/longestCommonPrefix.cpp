/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // find the shortest length word
        int shortest = strs[0].length(); 
        string res = ""; 
        
        for (auto word : strs) {
            if (shortest > word.length()) {
                shortest = word.length(); 
            }
        }
        
        int idx = 0; 
        // traverse each word in vector and compare its character with the first word in vector
        for (auto ch : strs[0]) {
            for (int i = 1; i < strs.size(); i++) {
                // if the current word's character is not equal to the first word's character or the index is longer than the shortest word then return res
                if (strs[i][idx] != ch || idx > shortest) {
                    return res; 
                }
            }
            // add the current character to res and increment idx to compare next character
            res += ch; 
            idx++; 
        }
        return res; 
    }
};
