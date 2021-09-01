class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        //starting pointer
        int i = 0;
        //next pointer
        for (int j = 1; j < nums.size(); j++) {
            //check if the next point is not equal to the starting pointer
            //if it is not equal to, swap the next element of starting pointer with next pointer
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
