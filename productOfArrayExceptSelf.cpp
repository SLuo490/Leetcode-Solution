#include <bits/stdc++.h>
using namespace std; 

vector<int> productExceptSelf(vector<int>& nums) {
    // initialize prefix and postfix arrays
    int n = nums.size(); 
    vector<int> prefix; 
    vector<int> postfix(n); 

    // O(N) 
    prefix.push_back(nums[0]); 
    for(int i = 1; i < nums.size(); i++) {
        int prod = nums[i] * prefix[i - 1]; 
        prefix.push_back(prod); 
    }

    // O(N)
    postfix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        int prod = nums[i] * postfix[i + 1]; 
        postfix[i] = prod; 
    }

    // calculate the result
    vector<int> res; 
    int prod = 1; 
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            prod = 1 * postfix[i + 1]; 
            res.push_back(prod); 
        } else if (i == n - 1) {
            prod = 1 * prefix[i - 1];
            res.push_back(prod); 
        } else {
            prod = prefix[i - 1] * postfix[i + 1]; 
            res.push_back(prod); 
        }
    }
    return res; 
}

int main() {
    vector<int> nums = {1,2,3,4}; 
    vector<int> res = productExceptSelf(nums); 

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " "; 
    }
    cout << endl;

    vector<int> nums2 = {-1,1,0,-3,3}; 
    vector<int> res2 = productExceptSelf(nums2); 

    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " "; 
    }
    cout << endl; 

    return 0; 
}