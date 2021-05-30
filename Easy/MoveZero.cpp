class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int anchor = 0;
        for (int explorer = 0; explorer < nums.size(); explorer++) {
            if (nums[explorer] != 0) {
                swap (nums[anchor], nums[explorer]);
                anchor++;
            }
        }
    }
};
