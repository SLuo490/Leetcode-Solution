#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_set<char> set;
    int res = 0;

    for (char ch : s) {
      // if the character is in the set, we know that the character is even, so
      // we add 2 and remove the character from set
      if (set.find(ch) != set.end()) {
        res += 2;
        set.erase(ch);
      } else {
        // if we see a character that is odd, we add it to the set
        set.insert(ch);
      }
    }

    // if the set is not empty, that means we need to add one of the odd
    // characters to the result (middle character of the palindrome)
    if (!set.empty()) {
      res++;
    }

    return res;
  }
};

int main() {
  Solution solution;
  string s = "abccccdd";
  int res = solution.longestPalindrome(s);
  cout << res << endl;

  string s2 = "a";
  int res2 = solution.longestPalindrome(s2);
  cout << res2;
  return 0;
}
