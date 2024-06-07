#include <iostream>
#include <istream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    istringstream sStream(sentence);
    unordered_set<string> dSet(dictionary.begin(), dictionary.end());
    string word;
    string res;

    while (getline(sStream, word, ' ')) {
      res += shortestRoot(word, dSet) + " ";
    }
    res.pop_back();
    return res;
  }

private:
  string shortestRoot(string word, unordered_set<string> dSet) {
    for (int i = 1; i <= word.length(); i++) {
      string root = word.substr(0, i);
      if (dSet.find(root) != dSet.end()) {
        return root;
      }
    }
    return word;
  }
};

int main() {
  Solution s;
  vector<string> dictionary = {"cat", "bat", "rat"};
  string sentence = "the cattle was rattled by the battery";
  cout << s.replaceWords(dictionary, sentence) << endl;
  return 0;
}
