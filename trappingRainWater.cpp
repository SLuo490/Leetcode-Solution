#include <bits/stdc++.h>
using namespace std; 

// Brute Force
// Time: O(N^2)
// Space: O(1)
int trap(vector<int>& height) {
    int res = 0; 
    for (int i = 0; i < height.size(); i++) {
        int leftMax = 0, rightMax = 0; 
        // find the left max
        for (int j = 0; j <= i; j++) {
            leftMax = max(leftMax, height[j]); 
        }

        // find the right max
        for (int k = i; k < height.size(); k++) {
            rightMax = max(rightMax, height[k]); 
        }

        res += min(leftMax, rightMax) - height[i]; 
    }
    return res; 
}


// Time : O(N)
// Space: O(1)
int trap2 (vector<int>& height) {
    int left = 0, right = height.size() - 1; 
    int leftMax = 0, rightMax = 0; 
    int res = 0; 

    while (left < right) {
        if (height[left] > leftMax) leftMax = height[left]; 
        if (height[right] > rightMax) rightMax = height[right]; 

        if (leftMax < rightMax) {
            res += leftMax - height[left]; 
            left++; 
        } else {
            res += rightMax - height[right];
            right--; 
        }
    }
    return res; 
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; 
    cout << trap(height) << endl;
}