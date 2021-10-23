/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: 1
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int room = 0; 
        sort(intervals.begin(), intervals.end()); 
      
        //minHeap
        priority_queue<int,vector<int>, greater<int>> pq; // greater<int> -> smallest value first
        
        for (auto interval : intervals) {
            int start = interval[0], end = interval[1]; // current start and end of interval
            
            while (!pq.empty() && pq.top() <= start) {
                pq.pop(); 
            }
            pq.push(end); 
            room = max(room, (int)pq.size()); 
        }
        return room; 
    }
};
