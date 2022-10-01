#include <bits/stdc++.h>
using namespace std;

/*
In a string s of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].
A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.

Example 1:
Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.

Example 2:
Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.

Example 3:
Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".
*/

class Solution {
public:
  // sliding window approach
  vector<vector<int>> largeGroupPositions(string s) { 
      vector<vector<int>> res; 
      int windowStart = 0; 
      int counter = 1; 
      for (int windowEnd = 1; windowEnd < s.length(); windowEnd++) {
          if (s[windowEnd - 1] != s[windowEnd]) {
              windowStart = windowEnd; 
              counter = 1; 
          } else {
              counter++; 
          }
          // cout << windowStart << " " << windowEnd << " " << counter << endl;  
          if (counter >= 3 && s[windowEnd + 1] != s[windowEnd]) {
              res.push_back({windowStart, windowEnd}); 
          }
      }
      return res; 
  }
  
  // cleaner solution 
  vector<vector<int>> largeGroupPositions(string s) { 
    vector<vector<int>> res; 
    for (int i = 0, j = 0; i < s.length(); i = j) {
      while (j < s.length() && s[j] == s[i]) j++; 
      if (j - i >= 3) {
        res.push_back({i, j - 1}); 
      }
    }    
    return res; 
};

int main()
{
  return 0;
}