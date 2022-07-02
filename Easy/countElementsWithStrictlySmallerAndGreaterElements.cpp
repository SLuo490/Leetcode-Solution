/*
  https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
  2148. Count Elements With Strictly Smaller and Greater Elements
  
  Given an integer array nums, return the number of elements that have both a strictly smaller and strictly greater element appear in nums.

  Example 1:
  Input: nums = [11,7,2,15]
  Output: 2
  Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
  Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
  In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

  Example 2:
  Input: nums = [-3,3,3,90]
  Output: 2
  Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
  Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
*/

#include <iostream>
#include <vector>

using namespace std; 

/*
  we need to find element in the nums that are both strictly greater and strictly smaller than the current element

  [11, 7, 2, 15]

  for num 7:
    11 is strictly greater than it and 2 is strictly smaller than it
  
  for num 11
    15 is strictly greater than it and 7 is strictly smaller than it

  returns 2
*/

int countElements(vector<int>& nums) {
  int res = 0; 
  bool strIncr = false, strDecr = false; 

  for (int i = 0; i < nums.size(); i++) {
    strIncr = false; 
    strDecr = false; 
    for (int j = 0; j < nums.size(); j++) {
      if (nums[i] < nums[j]) {
        strDecr = true; 
      } else if (nums[i] > nums[j]) {
        strIncr = true; 
      } else {
        continue; 
      }

      if (strIncr && strDecr) {
        res++; 
        break; 
      }
    }
  }
  return res; 
}

int main() {
  vector<int> nums = {11,7,2,15}; 
  cout << countElements(nums) << endl;

  vector<int> nums2 = {90}; 
  cout << countElements(nums2) << endl;

  return 0; 
}