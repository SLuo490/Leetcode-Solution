/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"
*/


class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i); 
                j = i + 1; 
            }
        }
        
        reverse (s.begin() + j, s.end()); 
        return s; 
    }
};

