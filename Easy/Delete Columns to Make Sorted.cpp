#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

Example 1:
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

Example 2:
Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.

Example 3:
Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.
*/

class Solution {
public:
  // Slow Solution
  int minDeletionSize(vector<string>& strs) {
    int res = 0; 
    for (int i = 0; i < strs[0].length(); i++) {
        string checkSorted = ""; 
        for (int j = 0; j < strs.size(); j++) {
            checkSorted += strs[j][i]; 
        }
        if (!isSorted(checkSorted)) res++; 
    }
    return res; 
  }
  
  bool isSorted(string checkSorted) {
    for (int i = 0; i < checkSorted.size(); i++) {
        for (int j = i + 1; j < checkSorted.size(); j++) {
            if (checkSorted[i] > checkSorted[j]) {
                return false; 
            }
        }
    }
    return true; 
  }

  // Faster Solution
  int minDeletionSize(vector<string>& strs) {
    int res = 0; 
    for (int col = 0; col < strs[0].size(); col++) {
        for (int row = 1; row < strs.size(); row++) {
            if (strs[row - 1][col] > strs[row][col]) {
                res++; 
                break; 
            }
        }
    }
    return res; 
  }
};

/*
    ["cba","daf","ghi"]
      -
    
    str = cdg
    
    traverse through the single characters
    add the single characters to string
    use a helper function that checks if it is sorted lexicographically 
        if helper is false 
        increment res 

    loop to the second character 

*/

int main()
{
  return 0;
}