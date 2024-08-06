#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    vector<int> freq(26, 0); // use vector since there can only be 26 letters
    for (char c : word) {
      freq[c - 'a']++;
    }

    // sort the freq by highest to lowers
    sort(freq.rbegin(), freq.rend());

    int res = 0;
    for (int i = 0; i < 26; i++) {
      // character not found in word
      if (freq[i] == 0)
        break;
      // there are 8 possible key assignments, we'll divide the frequency rank
      // by 8 to group it as a first, second, or third key press Calculate the
      // number of pushes for each letter based on its position in the sorted
      // list 8 + 1 because there dividing the frequencies will result in 0, 1,
      // and 2
      res += (i / 8 + 1) * freq[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.minimumPushes("abc") << endl;
  cout << s.minimumPushes("aab") << endl;
  cout << s.minimumPushes("leetcode") << endl;
  cout << s.minimumPushes("abcdefghijklmnopqrstuvwxyz") << endl;
}
