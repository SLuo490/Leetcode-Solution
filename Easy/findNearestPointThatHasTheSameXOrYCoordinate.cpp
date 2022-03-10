/*
You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.
Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.
The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).

Example 1:
Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
Output: 2
Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.

Example 2:
Input: x = 3, y = 4, points = [[3,4]]
Output: 0
Explanation: The answer is allowed to be on the same location as your current location.

Example 3:
Input: x = 3, y = 4, points = [[2,3]]
Output: -1
Explanation: There are no valid points.
*/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int manhattanDistance = INT_MAX; 
        int smallestIdx = -1; 
        
        for (int i = 0; i < points.size(); i++) {
            int x2 = points[i][0], y2 = points[i][1]; 
            if (x2 == x || y2 == y) {
                int currentManhattanDistance = abs(x - x2) + abs(y - y2); 
                if (currentManhattanDistance < manhattanDistance) {
                    manhattanDistance = currentManhattanDistance; 
                    smallestIdx = i; 
                }
            }
        }
        return smallestIdx; 
    }
};

/*

x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]

(3,4)

[3,1], [2,4], [2,3], [4,4]

calculate the manhattan distance between each of these four points

[[1,2],[3,1],[2,4],[2,3],[4,4]]
                           -

abs(3 - 3) + abs(4 - 1) = 3
manhattan distance = 3
smallest idx = 1

abs(3 - 2) + abs(4 - 4) = 1
manhattan distance = 1
smallest idx = 2

abs(3 - 2) + abs(4 - 3) = 2
manhattan distance = 1
smallest idx = 2

abs(4 - 3) + abs(4 - 4) = 1
manhattan distance = 1
smallest idx = 2

return 2

int manhattan distance = INT_MAX
int smallestIdx = -1 // if there is no valid point 
double for loop
    if points[i][0] == x || points[i][1] == y
        then calculate the current manhattan distance abs(x1 - x2) + abs(y1 - y2)
        if (current manhattan distance < manhattan distance) {
            manhattan distance = curr manhattan distance
            smallest idx = i;
        }
return smallest idx

*/
