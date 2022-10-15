#include <bits/stdc++.h>
using namespace std;

/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

Example 1:
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2:
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
*/

class Solution {
public:
    // Difference Array Method
    // Time: O(m + n)
    // Space: O(n + m)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // find the furthest trip
        int furthest = 0; 
        for (vector<int>& trip : trips) {
            furthest = max(furthest, trip[2]); 
        }
        
        // create array of size (furthest + 1)
        vector<int> arr(furthest + 1); 
        
        // traverse through trips and simulate road
        for (vector<int>& trip : trips) {
            int value = trip[0], left = trip[1], right = trip[2]; 
            arr[left] += value; 
            arr[right] -= value; 
        }
        
        // traverse through array, if sum is greater than capacity return false
        int count = 0; 
        for (int num : arr) {
            count += num; 
            
            if (count > capacity) {
                return false; 
            }
        }
        return true;
    }
};

/*
    [0,2,0,3,0,-2,0,-3]
    
    [[2,1,5],[3,3,7]]
    
    val = 3
    left = 3
    right = 7
    
    1) find the furthest trip (to)
    2) create an array of size (to + 1)
    3) traverse through trips
        3.1) increment value of left(from) by num passenger(value) to signify capacity
        3.2) decrement value of right(to) by num passenger(value) to signify leaving capacity
    4) traverse through the array and once the value is greater than capacity return false
       
       
    trips = [[2,1,5],[3,3,7]], capacity = 5
    
    [0,2,0,3,0,-2,0,0,-3]
    
    val = 3
    left = 3
    right = 7
    
    2 + 3 -2 - 3 = 0
*/

int main()
{
  return 0;
}