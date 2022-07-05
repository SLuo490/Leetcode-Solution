/*
Given an integer array nums sorted in non-decreasing order and an integer target, return true if target is a majority element, or false otherwise.
A majority element in an array nums is an element that appears more than nums.length / 2 times in the array.

Example 1:
Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.

Example 2:
Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

// Time: O(N)
// Space: O(N)
bool isMajorityElement(vector<int>& nums, int target) {
    unordered_map<int,int> freqMap; 

    for (int num : nums) {
        freqMap[num]++; 

        if (freqMap[num] > nums.size() / 2 && num == target) return true; 
    }
    return false; 
}

int main() {
    // return 0
    vector<int> nums = {10,100,101,101}; 
    cout << isMajorityElement(nums, 101) << endl;

    // return 1
    vector<int> nums2 = {2,4,5,5,5,5,5,6,6}; 
    cout << isMajorityElement(nums2, 5) << endl;
    return 0; 
}