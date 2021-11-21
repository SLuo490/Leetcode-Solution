/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/


class Solution {
public:
    void helper (vector<string>& res, int open, int close, int n, string str) {
        //base case: if open and close equals to n then we have a valid parentheses
        if (close == n && open == n) {
            res.push_back(str);
            return;
        }
        // if open is less than n then we can add a opening parentheses
        if (open < n) {
            str.push_back('('); 
            helper (res, open + 1, close, n, str); 
            str.pop_back(); 
        }
        
        // if close is less than open, then we can add a closing parentheses
        if (close < open) {
            str.push_back(')'); 
            helper (res, open, close + 1, n, str); 
            str.pop_back(); 
        }
    }
    
    //Backtracking
    vector<string> generateParenthesis(int n) {
        vector<string> res; 
        string str; 
        
        helper(res, 0, 0, n, str); 
        
        return res; 
    }
};

/*
() () ()
() (())
(()) ()
(()())
((()))

rule: 
3 open and 3 closed parentheses
close < open before we can add close parentheses
*/
