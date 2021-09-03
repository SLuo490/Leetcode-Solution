/*
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
*/


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for (auto ch : chars) {
            mp[ch]++;
        }
        
        string count ="";
        bool flag = true;
        
        
        for (auto str : words) {
            flag = true;
            unordered_map<char,int> cpyFreq;
            for (auto ch : str) {
                cpyFreq[ch]++;
            }
            
            for (auto ch : str) {
                if (cpyFreq[ch] > mp[ch]) {
                    flag = false;
                }
            }
            
            if (flag) {
                count += str;
            }
        }
        
        return count.length();
    }
};
