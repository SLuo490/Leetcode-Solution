// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int appendCharacters(string s, string t) {
    int i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
      if (s[i] == t[i]) {
        i++;
        j++;
      } else if (s[i] != t[j]) {
        i++;
      }
    }
    return t.length() - j;
  }
};

int main() {
  Solution solution;

  string test1s = "coaching";
  string test1t = "coding";
  int result1 = solution.appendCharacters(test1s, test1t);

  string test2s = "abcde";
  string test2t = "a";
  int result2 = solution.appendCharacters(test2s, test2t);
  cout << result1 << '\n' << result2 << endl;

  return 0;
}
