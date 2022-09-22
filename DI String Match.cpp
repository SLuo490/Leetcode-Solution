#include <bits/stdc++.h>
using namespace std;

/*
A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

Example 1:
Input: s = "IDID"
Output: [0,4,1,3,2]

Example 2:
Input: s = "III"
Output: [0,1,2,3]

Example 3:
Input: s = "DDI"
Output: [3,2,0,1]
*/

class Solution {
public:

    // Time: O(3N) Space: O(2N)
    vector<int> diStringMatch(string s) {
      vector<int> perm; 
      for (int i = 0; i <= s.length(); ++i) {
          perm.push_back(i); 
      }
      
      int left = 0, right = perm.size() - 1;

      vector<int> res; 
      for (int i = 0; i < s.length(); i++) {
          if (s[i] == 'I') {
              res.push_back(perm[left++]); 
          } else {
              res.push_back(perm[right--]); 
          }
      }
      
      for (int i = left; i <= right; i++) {
          res.push_back(perm[i]); 
      }
      
      return res; 
    }

    // Time: O(N) Space: O(N)
    vector<int> diStringMatch(string s) {        
        int left = 0, right = s.size();

        vector<int> res; 
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.size() || s[i] == 'I') {
                res.push_back(left++); 
            } else {
                res.push_back(right--); 
            }
        }
        
        return res; 
    }
};

/*
    s = "IDID" n = 4
         -
         
     I --> find the number such that perm[i] < perm[i + 1]
     D --> find the number such that perm[i] > perm[i - 1]
     
    s[i] == I --> lowest number
    [0, 1, 2, 3, 4]
    
    s[i] == D --> highest number
    [0, 4]
    
    s[i] == I --> second lowest number
    [0, 4, 1]
    
    s[i] == D --> second largest number
    [0, 4, 1, 3]
    
    end of loop, add the rest of the numbers 
 
*/

int main()
{
  return 0;
}