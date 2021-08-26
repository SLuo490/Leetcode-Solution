/*
Given a string s, return the length of the longest substring that contains at most two distinct characters.

Example 1:
Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.

Example 2:
Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
*/


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int windowStart = 0, maxLength = 0;
        unordered_map<char,int> mp;
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char rightChar = s[windowEnd];
            mp[rightChar]++;
            
            while (mp.size() > 2) {
                char leftChar = s[windowStart];
                mp[leftChar]--;
                if (mp[leftChar] == 0) {
                    mp.erase(leftChar);
                }
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};
