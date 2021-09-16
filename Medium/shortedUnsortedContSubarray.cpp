/*
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Example 1:
Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted

Example 2:
Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted

Example 3:
Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted
*/

class Solution {
public:
    int sorted(vector<int>& num) {
        int lo = 0;
        while (lo < num.size() - 1 && num[lo] <= num[lo + 1]) {
            lo++;
        }
        
        if (lo == num.size() - 1) {
            return 0;
        }
        return -1;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNum = nums;
        sort(sortedNum.begin(), sortedNum.end());
        int res = 0, i = 0, j = nums.size() - 1;

        if (sorted(nums) == 0) {
            return 0;
        } else {
            while (true) {
                while (nums[i] == sortedNum[i]) {
                    i++;
                }
                
                while (nums[j] == sortedNum[j]) {
                    j--;
                }
                
                res = j - i + 1;
                break;
            }
        }
        return res;
    }
};
