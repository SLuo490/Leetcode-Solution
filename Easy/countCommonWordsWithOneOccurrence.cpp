/*
Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

Example 1:
Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.

Example 2:
Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.

Example 3:
Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
*/

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1, mp2; 
        int res = 0; 
        
        for (auto str : words1) {
            mp1[str]++; 
        }
        
        for (auto str : words2) {
            mp2[str]++; 
        }
        
        for (int i = 0; i < words1.size(); i++) {
            string curr = words1[i]; 
            
            if (mp1.find(curr) != mp2.end() && (mp1[curr] == 1 && mp2[curr] == 1)) {
                res++; 
            }
        }
        
        return res; 
    }
};
