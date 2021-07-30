/*
Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        //add it to a vector
        vector<int> count(s.length());
        int idx = 0;
        count[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                idx++;
                count[idx] = 1;
            } else {
                count[idx]++;
            }
        }
        
        /*
        "10101"
         -
         [1]
         idx = 0;
         
        "10101"
          -
         [1,1]
         idx = 1;
         
        "10101"
           -
         [1,1,1]
         idx = 2;   
         
        "10101"
            -
         [1,1,1,1]
         idx = 3;
         
        "10101"
             -
         [1,1,1,1,1]
         idx = 4;
        */
        
        int res = 0;
        for (int i = 1; i <= count.size() - 1; i++) {
            // res += min(count[i],count[i + 1]); //give error
            res += min(count[i - 1], count[i]);
        }   
      
      /*
               [1,1,1,1,1]
               res += min(1,1) = 1
               res += min(1,1) = 2
               res += min(1,1) = 3
               res += min(1,1) = 4
      */
        return res;
    }
    
    //Optimized version of the previous example (linear scan)
    int countBinarySubstrings(string s) {
        int curr = 1, prev = 0, res = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] == s[i]) {
                curr++;
            } else {
                res += min(curr,prev);
                prev = curr;
                curr = 1;
            }

        }
        // return res; //this doesn't count the last minimum
        return res += min(curr,prev);
    }

};











