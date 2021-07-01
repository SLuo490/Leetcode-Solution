/*
A string is good if there are no repeated characters.
Given a string s, return the number of good substrings of length three in s.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
A substring is a contiguous sequence of characters in a string.

 
Example 1:
Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".

Example 2:
Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int size = s.size();
        int counter = 0;
        
        //hash map
        unordered_map<char, int> map;
        
        //store the first three character into map
        for (int i = 0; i < 3; i++)
        {
            map[s[i]]++;
        }
        
        //if there are 3 distinct character in map increment answer
        if (map.size() == 3)
        {
            counter++;
        }
        
        //loop through the rest of the string starting at index 3
        for (int i = 3; i < s.size(); i++)
        {
            //add the next character of the string to the map
            map[s[i]]++;
            
            //delete the first character of the map
            map[s[i-3]]--;
            
            //if frequence of character is 0, erase it from map
            if (map[s[i-3]]==0)
            {
                map.erase(s[i-3]);
            }
            
            //if there are 3 distinct character in map increment counter
            if (map.size() == 3)
            {
                counter++;
            }
        }

        return counter;
        
    }
};
