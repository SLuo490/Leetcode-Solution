/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/


//StudentID: 23716440
//Time Complexity: O(v+E)
//Space Complexity: O(V+E)

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graphs(n);
        for (auto prerequisit: prerequisites)
        {
            auto u = prerequisit[0], v = prerequisit[1];
            graphs[u].push_back(v);
            indegree[v] += 1;
        }
        queue<int> zero_in_degree;
        for (int i = 0; i < n; ++i){
            if (indegree[i] == 0) zero_in_degree.push(i);
        }
        vector<int> courses;
        while (!zero_in_degree.empty()){
            auto u = zero_in_degree.front();zero_in_degree.pop();
            courses.push_back(u);
            for (auto v : graphs[u]){
                indegree[v] -= 1;
                if (indegree[v] == 0) zero_in_degree.push(v);
            }
        }
        return courses.size() == n;   
    }
};
