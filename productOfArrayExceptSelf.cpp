#include <bits/stdc++.h>
using namespace std; 

// Time: O(N)
// Space: O(N)
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

// Time: O(N)
// Space: O(1)
vector<int> optimizedProductExceptSelf(vector<int>& nums) {
    int prefix = 1; 
    int postfix = 1;
    int n = nums.size();  

    vector<int> res(n); 

    // calculate the prefix
    for (int i = 0; i < nums.size(); i++) {
        res[i] = prefix; 
        prefix *= nums[i]; 
    }

    // calculate the postfix
    for (int i = res.size() - 1; i >= 0; i--) {
        res[i] = postfix * res[i]; 
        postfix *= nums[i]; 
    }

    return res; 
}

    /*
        In this example, we want to make it so we don't need to create a pre and postfix array
        we can do the calculation in the result array 

        Prefix 
        --------->
        [1,2,3,4]
         -
        1) initialize prefix as 1 and set result's first value as 1
        prefix = 1
        [1,0,0,0]

        2) multiply prefix with the first element in the nums and update prefix
        prefix *= 1 


        [1,2,3,4]
           -

        put prefix to the next index of output

        [1,1,0,0]

        multiply prefix with the current element in nums and update prefix
        prefix = 2

        [1,2,3,4]
             -

        put prefix to the next element of output
        [1,1,2,0]

        multiply prefix with the current element in nums and update prefix
        prefix = 6

        ...

        res = [1,1,2,6]
        prefix = 24


        Compute postfix: 
        postfix = 1
        1 * 6 = 6
        [1,1,2,6]
        1 * 4 = 4

        postfix = 4
        4 * 2 = 8
        [1,1,8,6]
        4 * 3 = 12

        postfix = 12
        12 * 1 = 12
        [1,12,8,6]
        12 * 2 = 24

        postfix = 24
        24 * 1 = 24
        [24,12,8,6]
        24 * 1 = 24

        return res    
    */

int main() {
    vector<int> nums = {1,2,3,4}; 
    vector<int> res = productExceptSelf(nums); 

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " "; 
    }
    cout << endl;

    vector<int> nums2 = {-1,1,0,-3,3}; 
    vector<int> res2 = optimizedProductExceptSelf(nums2); 

    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " "; 
    }
    cout << endl; 

    return 0; 
}