/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false
*/

class Solution {
public:
    bool detectCapitalUse(string str) {
        bool firstLetterCap = false;
        bool allLetterCap = false;
        bool noLetterCap = false;

        // If there is only one character
        if (str.length() == 1 && isupper(str[0])) {
            allLetterCap = true;
        }
        if (str.length() == 1 && islower(str[0])) {
            noLetterCap = true;
        }

        // If there is no character
        if (str.length() == 0) {
            return true;
        }

        // loop to check if only first letter is correct
        for (int i = 1; i < str.length(); i++) {
            if (isupper(str[0]) && islower(str[i])) {
                firstLetterCap = true;
            } else {
                firstLetterCap = false;
                break;
            }
        }

        // Loop to check if all letter is not capitalized
        for (int i = 1; i < str.length(); i++) {
            if (!isupper(str[i]) && !isupper(str[i - 1])) {
                noLetterCap = true;
            } else {
                noLetterCap = false;
                break;
            }

            if (i == str.length() - 1 && isupper(str[i])) {
                noLetterCap = false;
                break;
            }
        }

        // Loop to check if all letter is capitalized
        for (int i = 1; i < str.length(); i++) {
            if (!islower(str[i]) && !islower(str[i - 1])) {
                allLetterCap = true;
            } else {
                allLetterCap = false;
                break;
            }

            if (i == str.length() - 1 && islower(str[i])) {
                allLetterCap = false;
                break;
            }
        }

        return firstLetterCap || noLetterCap || allLetterCap ? true : false;
    }
};
