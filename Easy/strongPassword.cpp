/*
A password is said to be strong if it satisfies all the following criteria:

It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).

Given a string password, return true if it is a strong password. Otherwise, return false.

Example 1:
Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.

Example 2:
Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
*/
class Solution {
public:
    // Time: O(N)
    // Space: O(1)
    bool strongPasswordCheckerII(string password) {
        if (password.length() < 8) return false; 
        set<char> st = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'}; 
        
        // initialize the booleans
        bool containLower = false; 
        bool containUpper = false; 
        bool containDigit = false; 
        bool containSpecialChar = false; 
        
        for (int i = 0; i < password.length(); i++) {
            char ch = password[i]; 
            if (isupper(ch)) containUpper = true; 
            if (islower(ch)) containLower = true; 
            if (isdigit(ch)) containDigit = true; 
            if (st.count(ch) == 1) containSpecialChar = true; 
            
            if (i > 0 && password[i - 1] == password[i]) return false; 
        }
        
        if (containLower && containUpper && containDigit && containSpecialChar) {
            return true; 
        }
        return false; 
    }
};
