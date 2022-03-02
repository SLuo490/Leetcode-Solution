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
        priority_queue<int,vector<int>, greater<int>> pq; 
        
        for (auto interval : intervals) {
            int start = interval[0], end = interval[1]; // current start and end of interval
            
            //if the minimum element of heap is free, then we pop the top element and add it back with the ending time of current meeting
            while (!pq.empty() && pq.top() <= start) {
                pq.pop(); 
            }
            //if it is not free, we add the ending 
            pq.push(end); 
            room = max(room, (int)pq.size()); 
        }
        return room; 
    }
};

/*

    [[0,30],[5,10],[15,20]]
       -
       
    start = 0, end = 30
    pq: {30}
    room = 1
    
    --------------------------
    
    [[0,30],[5,10],[15,20]]
               -
    start = 5, end = 10
    30 <= 5
    pq: {10,30}
    room = 2
    
    --------------------------
    
    [[0,30],[5,10],[15,20]]
                      -
    start = 15, end = 20
    10 <= 15
    pq: {20,30}
    room = 2
    
    return 2

*/
