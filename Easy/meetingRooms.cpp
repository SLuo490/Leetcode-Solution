/*
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
 
Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: true
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end());
            //O(nlogn) Time, O(n) Space
//         vector<vector<int>> currInterval;
        
//         currInterval.push_back(intervals[0]);
//         for (int i = 1; i < intervals.size(); i++) {
//             if (currInterval.back()[1] > intervals[i][0]) {
//                 return false;
//             } else {
//                 currInterval.push_back(intervals[i]);
//             }
//         }
//         return true;
        
        //Faster than above (O(nlogn) Time, O(1) space)
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};

/*
sort the intervals 

[0,30][5,10][15,20]
    - 

30 > 5, so you can't attend return false

[2,4][7,10]
   -  -

*/
