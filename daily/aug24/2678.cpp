#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int countSeniors(vector<string> &details) {
    int res = 0;

    for (int i = 0; i < details.size(); i++) {
      int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');
      if (age > 60)
        res++;
    }

    return res;
  }
};

int main() {
  Solution sol;
  vector<string> details = {"7868190130M7522 ", " 5303914400F9211 ",
                            " 9273338290F4010 "};
  cout << sol.countSeniors(details) << endl;
}
