/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.length() - 1, j = b.length() - 1; 
        string res = ""; 
        
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0) {
                carry += a[i] == '1' ? 1 : 0; 
                i--; 
            }
            
            if (j >= 0) {
                carry += b[j] == '1' ? 1 : 0; 
                j--; 
            }
            
            res = (carry % 2 == 0 ? "0" : "1") + res; 
            carry /= 2; 
        }
        return res; 
    }
};
