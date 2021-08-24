/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int windowStart = 0;
        int res = 0;
        unordered_map<char,int> mp;
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            //add the right char
            char rightChar = s[windowEnd];
            mp[rightChar]++;
            
            while (mp.size() > k) {
                char leftChar = s[windowStart];
                mp[leftChar]--;
                if (mp[leftChar] == 0) {
                    mp.erase(leftChar);
                }
                windowStart++;
            }
            res = max(res, windowEnd - windowStart + 1);
        }
        return res;
    }
};
