#include <bits/stdc++.h>
using namespace std; 

/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

    Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
*/

/*
    Pseudo code
    
    create a set and all nums to it
    initialize result 
    traverse through the set
        get the current number in set
        check if the previous number is in set if it is, then we need to continue
            * because start of sequence, there are no previous number
        initialize current length to 1
        do a while loop until number + 1 is not in set anymore
            increment current length
            increment the number
        calculate the max sequence
    return the max sequence
*/

int longestConsecutive(vector<int>& nums) {
    // add numbers to a set; removing duplicate numbers
    unordered_set<int> s;
    for (int num : nums) {
        s.insert(num); 
    }

    // traverse through the numbers in set
    int res = 0; 
    for (auto it : s) {
        int num = it; 
        // why do you continue if the previous number is in set?
        // to find the start of the sequence, we need to check if the previous number is in set or not
        if (s.find(num - 1) != s.end()) continue; 
        int currLength = 1; 
        while (s.find(num + 1) != s.end()) {
            currLength++;
            num++; 
        }
        res = max(res, currLength); 
    }
    return res; 
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2}; 
    cout << longestConsecutive(nums) << endl;
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1}; 
    cout << longestConsecutive(nums2) << endl; 
    return 0; 
}