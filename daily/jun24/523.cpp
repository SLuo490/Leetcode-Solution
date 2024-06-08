#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    // Initialize the map with 0, -1 because we need to handle the case when the
    // sum is divisible by k and the length of the subarray is 2.
    // [1, 2], k = 3, running sum = 3 % 3 = 0 ==> 1 - (-1) will result in > 1
    mp[0] = -1;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (mp.find(sum % k) != mp.end()) {
        if (i - mp[sum % k] > 1) {
          return true;
        }
      } else {
        mp[sum % k] = i;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {23, 2, 4, 6, 7};
  int k = 6;
  cout << s.checkSubarraySum(nums, k) << endl;
  return 0;
}
