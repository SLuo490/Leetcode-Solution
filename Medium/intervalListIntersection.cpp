/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        
        sort(intervals.begin(), intervals.end());
        
        //push back the first interval to ans
        ans.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            //compare [i,x] with [i,0]
            if (ans.back()[1] >= intervals[i][0]) {
                //set ans.back()[1] to the max of ans.back()[1] and intervals[i][1]
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};


/*
[[1,3],[2,6],[8,10],[15,18]]
[1,3][2,6]
 3 > 2
 -> there is an overlap so we find the max of 1 and 6 -> 6
*/
