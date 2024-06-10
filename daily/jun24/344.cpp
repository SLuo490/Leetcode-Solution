#include <string>
#include <iostream>
#include <vector>

class Solution {
  public:
    void reverseString(std::vector<char>& s) {
      int i = 0;
      int j = s.size() - 1;
      while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; 
        j--; 
      }
    }
};  

int main() {
  Solution solution;
  std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  solution.reverseString(s);
  for (char c : s) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
  return 0;
}
