/*
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

Example 1:
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Example 2:
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

Example 3:
Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []
*/


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res; 
        if (firstList.size() == 0 || secondList.size() == 0) return res;
        
        int i = 0, j = 0; //two pointer to iterate both intervals
        
        while (i < firstList.size() && j < secondList.size()) {
            //check if there is an overlap between two list
            if ((firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1]) || 
                (secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1])) {
                res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            }
            
            //move i or j depending on which ending interval is less
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return res;
        
    }
};
/*
// 
   F           S
[10,20]     [5,30] => [5,20]
 
 10 >= 5 && 20 <= 30 => overlap 

(arr1[i].start >= arr2[j].start && arr1[i].start <= arr2[j].end) 

   F            S
[0,10]      [10,20] => [10,10]    
(arr2[j].start >= arr1[i].start && arr2[j].start <= arr1[i].end)

*/
