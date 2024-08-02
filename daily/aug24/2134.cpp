#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSwap(vector<int> &nums) {
    int totalOnes = count(nums.begin(), nums.end(), 1);
    if (totalOnes == 0)
      return 0;

    vector<int> doubleArray(nums.begin(), nums.end());
    doubleArray.insert(doubleArray.end(), nums.begin(), nums.end());

    int n = nums.size();
    int countZeros = 0;
    int minZeros = INT_MAX;

    // initizlize the start of window
    for (int i = 0; i < totalOnes; i++) {
      if (doubleArray[i] == 0)
        countZeros++;
    }

    // sliding window
    for (int i = totalOnes; i < 2 * n; i++) {
      // if the new element added to window is 0, increment countZeros
      if (doubleArray[i] == 0)
        countZeros++;

      // if the element removed from window is 0, decrement countZeros
      if (doubleArray[i - totalOnes] == 0)
        countZeros--;

      // update minZeros if the current window is in the original size
      if (i - totalOnes < n) {
        minZeros = min(minZeros, countZeros);
      }
    }

    return minZeros;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 0, 1, 0, 1, 0, 0, 1, 1, 0};
  cout << s.minSwap(nums) << endl;
  return 0;
}
