//Time Complexity: O(nlogn)
//Space Complexity: O(n)?

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            //automatically sorts the array
            pq.push(nums[i]);
            //6,5,4,3,2,1
        }
        for (int i = 0; i < k-1; i++)
        {
            pq.pop();
            
        }
        return pq.top();
    }
};
