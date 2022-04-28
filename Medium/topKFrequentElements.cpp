/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
  // Time: O(n log n)
  // Space: O(N); 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums; 
        
        // count frequency of the numbers in nums
        unordered_map<int,int> mp; 
        for (auto num : nums) mp[num]++; 
        
        // create a max-heap with max frequency first corresponding to its element (pair<int,int>)
        priority_queue<pair<int,int>> pq; 
        for (auto [a, b] : mp) {
            pq.push({b,a}); 
        }
        
        // push the top k element (pq.top().second) into res 
        vector<int> res; 
        while (k) {
            res.push_back(pq.top().second); 
            pq.pop(); 
            k--; 
        }
        return res; 
    }
};
