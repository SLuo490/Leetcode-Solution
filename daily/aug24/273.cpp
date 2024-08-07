#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string numberToWords(int num) {
    if (num == 0)
      return "Zero";

    vector<string> ones = {"",     "One", "Two",   "Three", "Four",
                           "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                            "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                            "Eighteen", "Nineteen"};
    vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string result = "";
    int chunkIdx = 0;

    while (num > 0) {
      int chunk = num % 1000;
      if (num % 1000 != 0) {
        result = chunkToWords(chunk, ones, teens, tens) + thousands[chunkIdx] +
                 " " + result;
      }
      num /= 1000;
      chunkIdx++;
    }

    string strRes = "";
    for (int i = 0; i < result.length(); i++) {
      if (result[i] == ' ' && result[i + 1] == ' ') {
        continue;
      }
      strRes += result[i];
    }

    strRes.pop_back();

    return strRes;
  }

  string chunkToWords(int chunk, vector<string> &ones, vector<string> &teens,
                      vector<string> &tens) {
    string result = "";
    if (chunk >= 100) {
      result += ones[chunk / 100] + " Hundred ";
      chunk %= 100;
    }

    if (chunk >= 20) {
      result += tens[chunk / 10] + " ";
      chunk %= 10;
    } else if (chunk >= 10) {
      result += teens[chunk - 10] + " ";
      return result;
    }

    if (chunk > 0) {
      result += ones[chunk] + " ";
    }

    return result;
  }
};

int main() {
  Solution solution;
  cout << solution.numberToWords(123) << endl; // One Hundred Twenty Three
  cout << solution.numberToWords(12345)
       << endl; // Twelve Thousand Three Hundred Forty Five
  cout << solution.numberToWords(1234567)
       << endl; // One Million Two Hundred Thirty Four Thousand Five Hundred
                // Sixty Seven
  cout << solution.numberToWords(1234567891)
       << endl; // One Billion Two Hundred Thirty Four Million Five Hundred
                // Sixty Seven Thousand Eight Hundred Ninety One
  return 0;
}
