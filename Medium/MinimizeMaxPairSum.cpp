class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //3,5,2,3
        //sort the nums
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size()/2; i++)
        {
            //2,3,3,5
            //2 + 5 = 7
            //3 + 3 = 6
            //max (7,6) = 7
            sum = max(sum, nums[i] + nums[nums.size() - 1 - i]);
        }
        return sum;
    }
};
