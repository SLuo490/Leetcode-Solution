class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_ones = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                count++;
                max_ones = max(count, max_ones);
            }
            else {
                count = 0;
            }
        }
        return max_ones;
    }
};
