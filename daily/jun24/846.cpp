#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool findGroup(vector<int> &hand, int groupSize, int i, int n) {
    int nextCard = hand[i] + 1;
    hand[i] = -1;
    int count = 1;
    i += 1;

    while (i < n && count < groupSize) {
      if (hand[i] == nextCard) {
        nextCard = hand[i] + 1;
        hand[i] = -1;
        count++;
      }
      i++;
    }
    return count == groupSize;
  }
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize != 0)
      return false;
    sort(hand.begin(), hand.end());
    for (int i = 0; i < hand.size(); i++) {
      if (hand[i] >= 0 && !findGroup(hand, groupSize, i, n)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int groupSize = 3;

  if (s.isNStraightHand(hand, groupSize)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
    ;
  }

  vector<int> hand2 = {1, 2, 3, 4, 5};
  int groupSize2 = 4;

  if (s.isNStraightHand(hand2, groupSize2)) {
    cout << "true" << endl;
  } else {
    cout << "false";
  }

  return 0;
}
