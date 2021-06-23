/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        
        //loop through string
        while (left < right) {
            //if left is not equal to right, check the next left or next right to see if it is valid
            if (s[left] != s[right]) {
                //loop through string at left + 1 or right - 1 to see if string is valid palidrome
                if (isValid(s, left + 1, right) || isValid(s, left, right - 1)) {
                    return true;
                } else {
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
    
    //check if two string at index left and index right is valid
    bool isValid (string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
