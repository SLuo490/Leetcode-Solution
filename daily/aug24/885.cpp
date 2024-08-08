#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    // south is {1, 0} because we moving down which is incrementing in array
    // {east, south, west, north}
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // initialize step at 1 which is starting step to move east
    int steps = 1;
    int current_direction = 0; // going east direction[current_direction] = east

    // initialize r and c which is rStart and cStart
    int r = rStart;
    int c = cStart;

    vector<vector<int>> res;
    res.push_back({rStart, cStart});

    // spiral logic
    while (res.size() < rows * cols) {
      // change direction of the spiral every 2 iterations
      for (int i = 0; i < 2; i++) {
        // loop until step
        for (int j = 0; j < steps; j++) {
          // increment r and c by the current direction
          r += directions[current_direction][0];
          c += directions[current_direction][1];

          // push the current r and c into result if r and c is in bounds of
          // rows and cols
          if (r >= 0 && r < rows && c >= 0 && c < cols) {
            res.push_back({r, c});
          }
        }
        // update the directions
        current_direction = (current_direction + 1) % 4;
      }
      steps++;
    }

    return res;
  }
};

/*
    we can use a vectory of directions(East, South, West, North) to keep track
   of the spiral's direction use step which to keep track how far to move in a
   direction (start at 1) initizlize the current direction which is 0 (since we
   move East first) will be used to change the spiral's direction initialize
   result

    push the current rStart and cStart into result

    - logic to spiral movement
        keep moving until result's size is the length of rows * cols
            first loop (since we want a spiral movement, we want to increase
   step after this loop every 2 iterations) second loop (move until number of
   steps) increment r by the vector direction[current direction][0] increment c
   by the vector direction[current direction][1]

                    add the {r,c} into result when the row and col is within
   bound update the direction: (current direction + 1) % 4 (i wouldn't get this)
   (0 -> 1 -> 2 -> 3 -> 0 -> 1 -> 2 -> ...) increment number of steps
*/

int main() {
  Solution s;
  vector<vector<int>> res = s.spiralMatrixIII(1, 4, 0, 0);
  for (auto r : res) {
    cout << r[0] << " " << r[1] << endl;
  }

  vector<vector<int>> res2 = s.spiralMatrixIII(5, 6, 1, 4);
  for (auto r : res2) {
    cout << r[0] << " " << r[1] << endl;
  }
  return 0;
}
