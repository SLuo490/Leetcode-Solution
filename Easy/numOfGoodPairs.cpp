/*
Given an array of integers nums.
A pair (i,j) is called good if nums[i] == nums[j] and i < j.
Return the number of good pairs.

Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:
Input: nums = [1,2,3]
Output: 0

*/

class Solution {
public:
    // BRUTE FORCE
    int numIdenticalPairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int j = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            j = i + 1;
            while (j < nums.size()) {
                if (nums[i] == nums[j]) {
                    counter++;
                } 
                j++;
            }
        }
        return counter;
    }
    
    //Hash Map
    int numIdenticalPairs(vector<int>& nums) {
        //add it to map
        //loop through map
            //res += the frequency of the character * frequency of character - 1 / 2
        int res = 0;
        unordered_map<int,int> mp;
        for (auto x : nums) {
            mp[x]++;
        }
        
        for (auto it : mp) {
            res += (it.second * (it.second - 1)) / 2;
        }
        return res;
    
    
//             [1,2,3,1,1,3]

//             3(1s) * 2 /2 =3
//             1(2s) = 0 
//             2(3s) * 1/2 =1

//             3 + 0 + 1 = 4
    }
    
    //OPTIMAL (Hash Map (100% runtime))
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            res += mp[nums[i]]++;
        }
        return res;
    } 
};
