#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    int scoreOfString(string s) {
        int res = 0; 
        for (int i = 1; i < s.length(); i++) {
            int prevNum = s[i - 1] - 'a';
            int currNum = s[i] - 'a'; 
            res += abs(prevNum - currNum); 
        }
        return res; 
    }
};

int main() {
  Solution sol;
  string s = "acb"; 
  cout << sol.scoreOfString(s) << endl; 
  return 0; 
}
