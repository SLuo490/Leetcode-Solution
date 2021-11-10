/*
Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. You can return the output in any order.
 
Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: s = "12345"
Output: ["12345"]

Example 4:
Input: s = "0"
Output: ["0"]
*/

class Solution {
public:
    void helper(string &s, vector<string>& res, int i) {
        //base case if i == size of s, then add it to res
        if (i == s.length()) {
            res.push_back(s); 
            return; 
        }
        
        helper(s, res, i + 1); 
        
        if (isalpha(s[i])) {
            //letter toggle
            s[i] ^= 32;  // Bitwise XOR with 32
            helper(s, res, i + 1); 
        }
        
        
        // No letter toggle
//         char c = s[i]; 
        
//         if (islower(c)) {
//             s[i] = toupper(c); 
//         } else {
//             s[i] = tolower(c); 
//         }
        
//         helper(s, res, i + 1); 
        
//         if (isalpha(c)) {
//             s[i] = c; 
//             helper(s, res, i + 1); 
//         }
    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res; 
        helper(s, res, 0); 
        return res; 
    }
};
