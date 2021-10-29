/*
Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.

Example 2:
Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".

Example 3:
Input: s = "zzzzz"
Output: 15
*/


class Solution {
public:
    int countHomogenous(string s) {
        int currCharLength = 0;
        int res = 0; 
        
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i - 1] == s[i]) {
                currCharLength++; 
            } else {
                currCharLength = 1; 
            }
            res = (res + currCharLength) % 1000000007;  
        }

        return res; 
    }
};

/*
abbcccaa
-

ma

a = 1
b = 1
bb = 2
c = 1
cc = 2
ccc = 3
a = 1
aa = 2


zzzzz

1 + 2 + 3 + 4 + 5 = 15



aaaa

1 + 2 + 3 + 4 = 10

n(n + 1) / 2 

4(4+1)/2

4(5)/2 = 10


3 (3 + 1) / 2

6

keep count of the current length of current character
    if character is next character is not different
        currChar ++
    else 
        calculate: 
        res += currChar length ( currChar length + 1) / 2 
        currChar = 1

*/
