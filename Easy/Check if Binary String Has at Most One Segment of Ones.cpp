#include <bits/stdc++.h>
using namespace std;

/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

Example 1:
Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:
Input: s = "110"
Output: true
*/

class Solution {
public:
  // Time: O(N)
  // Space: O(1)
  bool checkOnesSegment(string s) {
      if (s.length() == 1) return true;  
      
      int numSeg = 0; 
      
      for (int i = 0; i < s.length();) {
          int j = i + 1; 
          if (s[i] == '1') {
              while (s[j] == '1') {
                  j++; 
              }
              numSeg++; 
          }
          i = j; 
      }
      
      return numSeg == 1; 
  }

  // Check for '01' in the string s as the first character is always a 1
  // Time: O(N)
  // Space: O(1)
  bool checkOnesSegment(string s) {
      for (int i = 1; i < s.length(); i++) {
          if (s[i - 1] == '0' && s[i] == '1') {
              return false; 
          }
      }
      return true; 
  }
};

int main()
{
  return 0;
}