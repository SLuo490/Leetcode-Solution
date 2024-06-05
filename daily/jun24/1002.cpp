#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    vector<int> minFreq(26, INT_MAX);
    for (auto word : words) {
      vector<int> freq(26, 0);
      for (char ch : word) {
        freq[ch - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        minFreq[i] = min(minFreq[i], freq[i]);
      }
    }

    vector<string> res;
    for (int i = 0; i < 26; i++) {
      while (minFreq[i] > 0) {
        res.push_back(string(1, i + 'a'));
        minFreq[i]--;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<string> words = {"bella", "label", "roller"};
  vector<string> res = sol.commonChars(words);
  for (string s : res) {
    cout << s << " ";
  }
  cout << endl;

  vector<string> words2 = {"cool", "lock", "cook"};
  vector<string> res2 = sol.commonChars(words2);
  for (string s : res2) {
    cout << s << " ";
  }
  return 0;
}
