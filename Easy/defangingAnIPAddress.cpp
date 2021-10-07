/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
 
Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/

class Solution {
public:
    string defangIPaddr(string address) {
        if (address == "") return "";
        string replace = "[.]";
        string res = "";
        
        for (char ch : address) {
            if (ch != '.') {
                res += ch;
            } else {
                res += replace;
            }
        }
        return res;
    }
};
