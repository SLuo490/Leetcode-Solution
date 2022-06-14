/*
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.

Example 1:
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Example 2:
Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
*/

/*

    You are given an indices and a string s
        the index of indices correspond to the characters in string s
        
        [4,5,6,7,0,2,1,3] "codeleet"
        
        4 -> c
        5 -> o
        6 -> d
        ....
        3 -> t
        
    you want to return a new string sorted by indices 

    1) traverse indices 
        take index of indices[i]
        res[index] = s[i]
    2) return res

*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s; 
        
        for (int i = 0; i < indices.size(); i++) {
            int idx = indices[i]; 
            res[idx] = s[i]; 
        }
        
        return res; 
    }
};
