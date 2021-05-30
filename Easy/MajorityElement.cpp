class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCandidate = nums[0];
        int counter = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (counter == 0) {
                majorityCandidate = nums[i];
            }
            if (nums[i] == majorityCandidate) {
                counter++;
            }
            else {
                counter--;
            }

        }
        return majorityCandidate;
    }
    
};
