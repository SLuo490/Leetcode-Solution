#include <bits/stdc++.h>
using namespace std; 

int arithmeticTriplets(vector<int>& nums, int diff) {
    int res = 0; 
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                    res++; 
                }
            }
        }
    }
    return res; 
}


int main() {
    vector<int> nums = {0,1,4,6,7,10}; 
    int diff = 3; 

    cout << arithmeticTriplets(nums, diff) << endl;

    return 0; 
}