#include <bits/stdc++.h>
using namespace std; 

int trap (vector<int>& height) {
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