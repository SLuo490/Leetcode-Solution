#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    unordered_map<int, int> mp;
    for (int num : target) {
      mp[num]++;
    }

    for (int num : arr) {
      if (mp.find(num) != mp.end()) {
        mp[num]--;
      }

      if (mp[num] == 0) {
        mp.erase(num);
      }
    }
    return mp.empty();
  }
};

int main() {
  Solution sol;
  vector<int> target = {1, 2, 3, 4};
  vector<int> arr = {2, 4, 1, 3};

  if (sol.canBeEqual(target, arr)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
