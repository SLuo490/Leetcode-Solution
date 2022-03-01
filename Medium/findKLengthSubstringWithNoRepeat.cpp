/*
Given a string s and an integer k, return the number of substrings in s of length k with no repeated characters.

Example 1:
Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation: There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:
Input: s = "home", k = 5
Output: 0
Explanation: Notice k can be larger than the length of s. In this case, it is not possible to find any substring.
*/

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int windowStart = 0, counter = 0; 
        unordered_map<char,int> mp; 
        
        // return the length pf the string if k = 1
        if (k == 1) return s.length(); 
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char rightChar = s[windowEnd]; 
            mp[rightChar]++; 
            
            if (mp.size() == k) {
                counter++; 
            }
            
            while (windowEnd - windowStart + 1 >= k || mp[rightChar] > 1) {
                char leftChar = s[windowStart++]; 
                mp[leftChar]--; 
                
                if (mp[leftChar] == 0) {
                    mp.erase(leftChar); 
                }
            }
        }
        return counter; 
    }
};
