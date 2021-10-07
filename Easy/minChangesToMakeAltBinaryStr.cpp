/*
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
Return the minimum number of operations needed to make s alternating.

Example 1:
Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.

Example 2:
Input: s = "10"
Output: 0
Explanation: s is already alternating.

Example 3:
Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
*/


class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0, cnt2 = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == s[i] - '0') {
                cnt1++;
            } else if (i % 2 != s[i] - '0'){
                cnt2++;
            }
        }
        return min(cnt1,cnt2);
        
        
        /*
            0100
            -
            
            int i = 0
            0 % 2 = 0 && s[i] - '0' = 0
            cnt1 = 1
            
            0100
             -
             
            int i = 1
            1 % 2 = 1 && s[i] - '0' = 1
            cnt1 = 2
            
            0100
              -
             
            int i = 2
            2 % 2 = 0 && s[2] - '0' = 0
            cnt1 = 3
            
            0100
               -
            
            int i = 3
            3 % 2 = 1 && s[3] - '0' != 1
            cnt2 = 1
            
            min (3, 1) = 1
            
            returns 1
              
        */
    }
};
