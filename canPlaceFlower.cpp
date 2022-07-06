/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/

#include <iostream>
#include <vector>

using namespace std; 

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int res = 0, next = 0, prev = 0; 
    for (int i = 0; i < flowerbed.size(); i++) {
        if (flowerbed[i] == 0) {
            // if i is the first element and is 0, make prev to 0 else prev to previous element 
            if (i == 0) {
                if (i == 0) {
                    prev = 0; 
                } else {
                    prev = flowerbed[i - 1]; 
                }
            }
            // if i is the last element and is 0, make next to 0 else next to next element
            if (i == flowerbed.size() - 1) {
                next = 0; 
            } else {
                next = flowerbed[i + 1]; 
            }

            // if both next and prev are 0 then decrement n and set the element to 1
            if (next == 0 && prev == 0) {
                res++; 
                flowerbed[i] = 1; 
            }
        }
    }
    return res >= n; 
}


int main() {
    vector<int> flowerbed = {0,0,0,0,1};
    int n = 1;
    cout << canPlaceFlowers(flowerbed, n) << endl;

    return 0; 
}