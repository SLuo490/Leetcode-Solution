/*
Share
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        //convert all to lowercase and erase special character (spaces, comma, etc)
        for (char c : s) {
            if (isalnum(c)) {
                res += tolower(c);
            }
        }
        
        //two pointer check if palidrome
        int j = res.length() - 1;
        
        for (int i = 0; i < res.length() / 2; i++) {
            if (res[i] != res[j]) {
                return false;
            }
            j--;
        }
        return true;
        
        //slower runtime
        // for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        //     //move to the first alphabet
        //     while (i < j && !isalnum(s[i])) {
        //         i++;
        //     }
        //     //move to the first alphabet
        //     while (i < j && !isalnum(s[j])) {
        //         j--;
        //     }
        //     if (tolower(s[i]) != tolower(s[j])) {
        //         return false;
        //     }
        // }
        // return true;
    }
};
