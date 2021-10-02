/*
Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.

Example 1:
Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"

Example 2:
Input: nums = ["123","4","12","34"], target = "1234"
Output: 2
Explanation: Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"
*/


class Solution {
public:
    //O(N^2) Time and O(1) Space
    int numOfPairs(vector<string>& nums, string target) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0 ; j < nums.size(); j++) {
                if (i != j && nums[i] + nums[j] == target) {
                    counter++;
                }
            }
        }
        return counter;
    }
};
