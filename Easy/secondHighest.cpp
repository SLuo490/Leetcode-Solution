/*
Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
An alphanumeric string is a string consisting of lowercase English letters and digits.

Example 1:
Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.

Example 2:
Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit. 
*/


class Solution {
public:
    int secondHighest(string s) {
        //Time: O(N)
        //Space: O(N)
        //edge case: 
        if (s.length() <= 1) {
            return -1;
        }
        set<int> res;
        //add digits to set
        for (char c : s) {
            if (isdigit(c)) {
                res.insert(c-'0');
            }
        }
        //edge case:
        if (res.size() < 2) return -1;
        //iterate to the second index in set;
        auto resIt = res.rbegin();
        return *(++resIt);
        
        //Time: O(N)
        //Space: O(1)
        int n = s.length();
        int max = -1, secondMax = -1;
        
        //loop through string s
        for (int i = 0; i < n; i++) {
            //if number is a integer, set max/second max
            if (s[i] >= '0' && s[i] <= '9') {
                //problem
                // int nums = s[i];
                int nums = s[i] - '0';
                if (nums > max) {
                    //dfa12321afd
                        //secondMax = -1
                        //max = 1
                    secondMax = max;
                    max = nums;
                } else if (nums < max && nums > secondMax) {
                    secondMax = max;
                }
            }
        }
        return secondMax;
    }
};
