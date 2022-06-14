/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

Example 1:
Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.

Example 2:
Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;         
        pair<int,int> currPath = {0,0}; 
        s.insert(currPath); 
        
        for (int i = 0; i < path.length(); i++) {
            // simulate the path
            if (path[i] == 'N') {
                currPath.first+= 1; 
            } else if (path[i] == 'E') {
                currPath.second+=1; 
            } else if (path[i] == 'S') {
                currPath.first-=1; 
            } else {
                currPath.second-=1; 
            }
            
            // if currPath is in set, return true, else add to set
            if (s.find(currPath) != s.end()) {
                return true; 
            } else {
                s.insert(currPath); 
            }
        }
        return false; 
    }
};
