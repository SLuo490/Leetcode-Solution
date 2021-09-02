/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
Return the maximum total number of units that can be put on the truck.

Example 1:
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

Example 2:
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
*/

class Solution {
public:
    //Find the index of the boxTypes that have the max boxUnits
    int findMaxUnitsIdx (vector<vector<int>>& boxTypes) {
        int maxBoxUnit = 0;
        int maxBoxUnitIdx = -1;
        
        for (int i = 0; i < boxTypes.size(); i++) {
            if (boxTypes[i][1] > maxBoxUnit) {
                maxBoxUnit = boxTypes[i][1];
                maxBoxUnitIdx = i;
            }
        }
        return maxBoxUnitIdx;
    }
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int unitCount = 0;
        int remainingTruckSize = truckSize;
        //calculate the unitCount
        while (remainingTruckSize > 0) {
            int maxUnitIdx = findMaxUnitsIdx(boxTypes);
            if (maxUnitIdx ==  -1) break; //box unit is already used
            int boxCount = min(remainingTruckSize, boxTypes[maxUnitIdx][0]);
            unitCount += boxCount * boxTypes[maxUnitIdx][1];
            boxTypes[maxUnitIdx][1] = -1;
            remainingTruckSize -= boxCount;
        }
        return unitCount;
    }
};

/*

1) boxTypes = [# box, # unit per box]
2) truck size that can fit the maximum number of boxes


boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4

(1 * 3) + (2 * 2) + (1 * 1) = 3 + 4 + 1 = 8

* We need to find the maximum unit in boxType (helper function)
    * [1,3], how do we calculate the total?
    * total += boxType (1 * 3)

[1,3]

4 - 1 = 3

[2,2]

3 - 2 = 1

[1,1]

1 - 1 = 0

---------------------------------------------

[[5,10],[2,5],[4,7],[3,9]], truckSize = 10

[5,10] 
10 - 5 = 5

[3,9] 
5 - 3 = 2

[4,7]
2 - 2 = 0

(5 * 10) + (3 * 9) + (2 * 7) = 50 + 27 + 14 = 77 + 14 = 91

*/
