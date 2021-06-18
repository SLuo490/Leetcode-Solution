class Solution {
public:
    /*
         0 1 2 3 4 5
        [2,3,1,2,4,3]
                   -
                   -
        i = 0
        j = 0
        sum = 0
        res = INT_MAX
        -------------
        i = 0
        j = 0
        sum = 2
        res = INT_MAX
        -------------
        i = 1;
        j = 0;
        sum = 5
        res = INT_MAX
        -------------
        ....
        -------------
        i = 3
        j = 0;
        sum = 8
            res = (res, i - j + 1) => (INT_MAX, 3 - 0 + 1) = 4 => res = 4 
            sum -= num[j] => sum = 8 - 2 = 6
            j = 1
        -------------
        i = 4
        j = 1
        sum = 6 + 4 = 10
            res = (4, 4 - 1 + 1) => (4, 4) = 4
            sum -= num[j] => sum = 10 - 3 = 7
            j = 2
        sum = 7 
            res = (4, 4 - 2 + 1) = 3
            sum -= num[j] => sum = 7 - 1 = 6
            j = 3
        --------------
        i = 5
        j = 3
        sum = 9
            res = (3, 5 - 3 + 1) => (3,3) 3
            sum -= num[j] = 9 - 2 = 7
            j = 4
        sum = 7
            res = (3, 5 - 4 + 1) => (3, 2) = 2
            sum-= num[j] =  7 - 2 = 5
            j = 5
        //end of loop
        //return res => 2
    */
    int minSubArrayLen(int target, vector<int>& nums) {
        //two pointer i, j
        int i = 0;
        int j = 0;
        //result to the max int since we are finding the minimum subarray
        int res = INT_MAX;
        //sum to keep track of the subarray 
        int sum = 0;
        for (i = 0; i < nums.size(); i++)
        {
            //add each num in nums until sum is >= target
            sum += nums[i];
            while (sum >= target) 
            {
                //the minimum of res and the total index of the sum that is >= target
                res = min(res, i - j + 1);
                //decrement sum with the value at j to find the next min subarray
                sum -= nums[j];
                j++;
            }
        }
        //if there is no value where the sum of subarray in nums is >= target, return 0
        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};
