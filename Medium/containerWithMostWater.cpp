/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16

Example 4:
Input: height = [1,2,1]
Output: 2

*/


class Solution {
public:
    //O(N) Time and O(1) Space?
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0; 
        int maxArea = 0; 
        int lo = 0, hi = height.size() - 1; 
                
        while (lo < hi) {
            //calculate the height
            int currMax = max(height[lo], height[hi]); 
            int h = abs(height[lo] - height[hi]); 
            h = currMax - h; 
            
            //calculate the length
            int length = hi - lo; 
            
            //calculate the area
            maxArea = max(maxArea, length * h); 
            
            //move the two pointer
            if (height[lo] < height[hi]) {
                lo++; 
            } else {
                hi--; 
            }
        }
        
        return maxArea; 
    }
};

/*
[1,8,6,2,5,4,8,3,7]
   -  
               -
                      
//This calculates the height
1 - 7 = -6
7 - 6 = 1

//Thie calculates the distance:
hi - lo = 8 - 0 = 8

//calculate the area and compare it to max area so far

maxArea = max (maxArea, 8 * 1)

//Move lo if the number is less than hi

8 - 7 = 1
8 - 1 = 7

8 - 1 = 7

maxArea = 49


8 > 7


--------------------

8 - 3 = 5
8 - 5 = 3

7 - 1 = 6


*/
