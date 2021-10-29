/*
Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.

Example 2:
Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.

Example 3:
Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.

Example 4:
Input: s = "000"
Output: 0
*/


class Solution {
public:
    int numSub(string s) {
        int cnt = 0, res = 0; 
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                cnt++; 
            } else {
                cnt = 0; 
            }
            res = (res + cnt) % 1000000007; 
        }
        return res; 
    }
};

/*
111111


6 (7) / 2

42 / 2 = 21


2 (3) / 2
3

3(4) / 2
6

6 + 3 = 9

*/
