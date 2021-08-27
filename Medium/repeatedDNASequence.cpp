/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
  - For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> mp;
        //loop through string s, add the first 10 char to map
        //if the 10 char is already in map add it to res
        for (int i = 0; i + 9 < s.length(); i++) {
            string str = s.substr(i, 10);
            mp[str]++;
            if (mp[str] == 2) {
                res.push_back(str);
            }
        }
        return res;
    }
};


/*
 -
"AAAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 -
     
     
//Repeat until end of loop
  //Add the first 10 character as a string to map
  //if the mp of the string is == 2 then there is a repeat, add it to vector res


*/
