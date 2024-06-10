#include <iostream>
#include <vector>

class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> sorted = heights;
    sort(sorted.begin(), sorted.end());
    int count = 0;
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != sorted[i]) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution solution;
  vector<int> heights = {1, 1, 4, 2, 1, 3};
  std::cout << solution.heightChecker(heights) << std::endl;
  return 0;
}
