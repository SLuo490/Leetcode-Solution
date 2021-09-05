/*
There are 8 prison cells in a row and each cell is either occupied or vacant.
Each day, whether the cell is occupied or vacant changes according to the following rules:

- If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
- Otherwise, it becomes vacant.

Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
Return the state of the prison after n days (i.e., n such changes described above).

 
Example 1:
Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:
Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
Output: [0,0,1,1,1,1,1,0]
*/

//TLE
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        //loop until n is zero
        
            //create a vector
            //loop through the vector
                //if it is the first index and it is 1, add 0 to vector
                // check index - 1 and index + 1 and see if it matches
                    //it matches, then make it occupied (1)
                    //else 
                        //does not match add 0
                // if last index is 1 then make it 1
            //make cell = vector
        
        //return cell
        
//         int size = cells.size();
//         while (n != 0) {
//             vector<int> nextCell;
//             for (int i = 0; i < cells.size() - 1; i++) {
//                 if (i == 0) {
//                     nextCell.push_back(0);
//                 } else if (cells[i - 1] == cells[i + 1]) {
//                     nextCell.push_back(1);
//                 } else if (cells[i - 1] != cells[i + 1]) {
//                     nextCell.push_back(0);
//                 } else {
//                     nextCell.push_back(0);
//                 }
//             }
//             nextCell.push_back(0);
//             cells = nextCell;
//             n--;
//         }
//         return cells;
        
        //Cleaner version of above
        
        while (n > 0) {
            n--;
            vector<int> cells2(8);
            for (int i = 1; i < 7; i++) {
                if (cells[i - 1] == cells[i + 1]) {
                    cells2[i] = 1;
                } else {
                    cells2[i] = 0;
                }
            }
            cells = cells2;
        }
        return cells;
    }
};

/*

*If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
*vacant

[0, 1, 0, 1, 1, 0, 0, 1]
[0] => becomes vacant because there no adjacent neighbors

[0,1,0]
   -
becomes a 1 because its adjacent neighbors [i - 1] and [i + 1] are both vacant 

[0,1,0,1]
     -
becomes a 1 because its adjacent neightbors are both occupied

[0,1,1,1,1]
       -

first and last shell does not have adjacent neighbors

1 = occupied
0 = vacant

return after n days



[0, 1, 0, 1, 1, 0, 0, 1] n = 0

[0, 1, 1, 0, 0, 0, 0, 0] n = 1

[0, 0, 0, 0, 1, 1, 1, 0] n = 2

[0, 1, 1, 0, 0, 1, 0, 0] n = 3

[0, 0, 0, 0, 0, 1, 0, 0] n = 4

creates a new vector every day? 










*/
