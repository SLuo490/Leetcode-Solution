/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:
Input: grid = [" /","/ "]
Output: 2

Example 2:
Input: grid = [" /","  "]
Output: 1

Example 3:
Input: grid = ["\\/","/\\"]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)

Example 4:
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)

Example 5:
Input: grid = ["//","/ "]
Output: 3
*/

//Time Complexity: O(N * N * a(N))
//Space Complexity: O(N * N)

class Solution {
public:
    int count, n;
    vector<int> f;

   int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        //fill up vector f with values 0 - 4 * n * n
        count = n * n * 4;
        for (int i = 0; i < n * n * 4; ++i)
            f.push_back(i);
       
        //loop through grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //union top
                if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
                //union left
                if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3));
                
                //if grid is '\'
                /*
                 \   0  
                3   \    1
                    2  \
                */
                if (grid[i][j] != '/') {
                    //combine 0 and 1
                    uni(g(i , j, 0), g(i , j,  1));
                    //combine 3 and 2
                    uni(g(i , j, 2), g(i , j,  3));
                }
                
                //if grid is '/'
                /*
                     0 /
                 3   /    1
                   /  2   
                */
                if (grid[i][j] != '\\') {
                    //combine 0 and 3
                    uni(g(i , j, 0), g(i , j,  3));
                    //combine 1 and 2
                    uni(g(i , j, 2), g(i , j,  1));
                }
            }
        }
        return count;
    }
    
    //union
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x != y) {
            f[x] = y;
            count--;
        }
    }
    //path compression
    int find(int x) {
        //recursion
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    
    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
};
