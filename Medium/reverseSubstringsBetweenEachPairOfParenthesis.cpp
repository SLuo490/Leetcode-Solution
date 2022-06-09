class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> openBracket; 
        string res = ""; 
        
        for (int i = 0; i < s.length(); i++) {
            // if current element is open index, append the length of res
            if (s[i] == '(') {
                openBracket.push_back(res.length()); 
            } else if (s[i] == ')') {
                // once we reach the closing bracket, reverse up to the first opening bracket
                int j = openBracket.back(); 
                openBracket.pop_back(); 
                reverse(res.begin() + j, res.end()); 
            } else {
                // add to string if no closing or opening bracket
                res += s[i]; 
            }
        }
        return res; 
    }
};

/*
(u(love)i)

1) 
(u(love)i)
- 
res = ""
openBracket = {0}

2)
(u(love)i)
      -
res = "ulove"
openBracket = {0, 1}

3) 
(u(love)i)
       -
res = "ulove"
j = 1
openBracket = {0}
res = "uevol" => reverse res starting from + 1

4)
(u(love)i)
         -
res = "uevoli"
j = 0
openBracket = {}
res = "iloveu" => reverse res starting from + 0

return res

*/
