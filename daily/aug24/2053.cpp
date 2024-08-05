#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> freq;
    for (string &s : arr) {
      freq[s]++;
    }

    for (string &s : arr) {
      if (freq[s] == 1) {
        k--;
      }

      if (k == 0) {
        return s;
      }
    }

    return "";
  }
};

int main() {
  Solution s;
  vector<string> arr = {"d", "b", "c", "b", "c", "a"};
  cout << s.kthDistinct(arr, 2) << endl;
}
