#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> prefixSum;
    int res = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        prefixSum.push_back(sum);
      }
    }
    sort(prefixSum.begin(), prefixSum.end());
    for (int i = left - 1; i < right; i++) {
      res = (res + prefixSum[i]) % mod;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  int n = 4, left = 1, right = 5;
  cout << s.rangeSum(nums, n, left, right) << endl;
  return 0;
}
