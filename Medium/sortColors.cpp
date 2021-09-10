/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]
*/

class Solution {
public:
    //helper function to swap two pointer (need this instead of normal swap() function)
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        //if number is 0 then swap the 0s with low since it is the lowest number
        //if number is 2, then swap the 2s with hi since it is the highest number
        //if number is 1, then just increment the loop counter
        for (int i = 0; i <= hi; ) {    // Make sure to loop until hi 
            if (nums[i] == 0) {
                swap(nums, i , lo);
                // swap(nums[i] , lo); // this swap function doesn't work need helper function
                i++;
                lo++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums, i , hi);
                // swap(nums[i] , hi); // this swap function doesn't work need helper function
                hi--;
            }
        }
    }
};

/*
test:

 i
[1,0,2,1,0]
lo       hi
 
      i
1) [1,0,2,1,0]    => i index is 0, so swap it with lo index and increment i and lo
   lo       hi


        i
2) [0,1,2,1,0]    => ith index is 2, so swap it with hi index and decrement hi
     lo     hi
     
        i
2) [0,1,0,1,2]    => ith index is 0, so swap it with lo and increment i and lo
     lo   hi
     
          i
2) [0,0,1,1,2]    => ith index is 1, so increment i
        lohi
        
        
          i
2) [0,0,1,1,2]    => end of loop return 
          hi
          lo
     

*/
