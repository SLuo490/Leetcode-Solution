/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Example 2:
Input: n = 1, k = 1
Output: [[1]]
*/


class Solution {
public:
    vector<vector<int>> ans; 
    void dfs(int i, int k, vector<int>& curr, int n) {
        //base case: once size of curr reach k, then we have one combination
        if (curr.size() == k) {
            ans.push_back(curr); 
            return; 
        }
        
        for (int idx = i; idx < n + 1; idx++) {
            curr.push_back(idx); 
            dfs(idx + 1, k, curr, n); // generate combinations of idx
            curr.pop_back(); //pop curr and go to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr; 
        dfs(1, k, curr, n); 
        return ans; 
    }
};

/*
n = 4, k = 2

1-4

[1,2]
[1,3]
[1,4]
[2,3]
[2,4]
[3,4]

*/
