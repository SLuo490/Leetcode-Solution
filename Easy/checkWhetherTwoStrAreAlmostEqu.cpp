/*
Two strings word1 and word2 are considered almost equivalent if the differences between the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.
Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.
The frequency of a letter x is the number of times it occurs in the string.

Example 1:
Input: word1 = "aaaa", word2 = "bccb"
Output: false
Explanation: There are 4 'a's in "aaaa" but 0 'a's in "bccb".
The difference is 4, which is more than the allowed 3.

Example 2:
Input: word1 = "abcdeef", word2 = "abaaacc"
Output: true
Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 1 time in word1 and 4 times in word2. The difference is 3.
- 'b' appears 1 time in word1 and 1 time in word2. The difference is 0.
- 'c' appears 1 time in word1 and 2 times in word2. The difference is 1.
- 'd' appears 1 time in word1 and 0 times in word2. The difference is 1.
- 'e' appears 2 times in word1 and 0 times in word2. The difference is 2.
- 'f' appears 1 time in word1 and 0 times in word2. The difference is 1.

Example 3:
Input: word1 = "cccddabba", word2 = "babababab"
Output: true
Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 2 times in word1 and 4 times in word2. The difference is 2.
- 'b' appears 2 times in word1 and 5 times in word2. The difference is 3.
- 'c' appears 3 times in word1 and 0 times in word2. The difference is 3.
- 'd' appears 2 times in word1 and 0 times in word2. The difference is 2.
*/

class Solution {
public:
    //My first solution
    bool checkAlmostEquivalent(string word1, string word2) {
        //add word1 and word2 to mp
        unordered_map<char,int> mp1, mp2; 
        for (auto ch : word1) {
            mp1[ch]++; 
        }
        
        for (auto ch : word2) {
            mp2[ch]++; 
        }
        
        //loop through word 1
        for (int i = 0; i < word1.length(); i++) {
            char ch = word1[i];
            char ch2 = word2[i]; 
            
            //if ch is in both mp1 and mp2, check the abs value of mp1[ch] - mp2[ch] > 4
            if (mp1.find(ch) != mp1.end() && mp2.find(ch) != mp2.end() && abs(mp1[ch] - mp2[ch]) > 3 
                || mp1.find(ch2) != mp1.end() && mp2.find(ch2) != mp2.end() && abs(mp1[ch2] - mp2[ch2]) > 3)
            {
                return false; 
            }
            
            //if ch is in either mp1 and mp2 and is greater than 4, return false
            if ((mp1.find(ch) == mp1.end() && mp2[ch] > 3) || (mp2.find(ch) == mp2.end() && mp2[ch] > 3)
                || (mp1.find(ch2) == mp1.end() && mp2[ch2] > 3) || (mp2.find(ch2) == mp2.end() && mp2[ch2] > 3))
            
            {
                return false; 
            }
        }
        return true; 
    }
    
    //Cleaner Solution
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> mp1; 
        
        for (int i = 0; i < word1.size(); i++) {
            mp1[word1[i]]++; 
        }
        
        for (int i = 0; i < word2.size(); i++) {
            mp1[word2[i]]--; 
        }
        
        for (auto it : mp1) {
            if (abs(it.second) > 3) {
                return false; 
            }
        }
        return true; 
    }
};
