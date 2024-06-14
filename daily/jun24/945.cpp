class Solution {
public:
    // TLE
    // int minIncrementForUnique(vector<int>& nums) {
    //     int res = 0; 
    //     unordered_set<int> set; 

    //     for (int num : nums) {
    //         while (set.find(num) != set.end()) {
    //             num++; 
    //             res++; 
    //         }
    //         set.insert(num); 
    //     }
    //     return res; 
    // }

    // TIme: O(nlogn)
    // Space: O(1)
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int res = 0; 

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] + 1 - nums[i]; 
                res += increment; 

                nums[i] = nums[i - 1] + 1; 
            }
        }
        return res; 
    }
};

/*
    for each number in nums
        check if nums is in map
        if nums is in the map
            increment the current number until it is not in map
            increment res
        add number to map
*/
