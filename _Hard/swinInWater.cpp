//Student ID: 23716440
//Time Complexity: O(N^2 * log N)
//Space Complexity: O(N^2)

//1e5 is 100,000
int INF = 1e5;
//seen or visited
int seen[100][100];

class Solution {
public:
    int N;
    vector<vector<int>> grid;
    bool dfs(int t, int i, int j) 
    {
        //edge cases: 
        //out of bound
        if (i < 0 || i >= N || j < 0 || j >= N) return false;
        //cannot reach with current time
        if (grid[i][j] > t) return false;
        //visited 
        if (seen[i][j]) return false;
        
        //set i,j to visited 
        seen[i][j] = 1;
        //base case
        if (i == N - 1 && j == N - 1) return true;
        //recursion
        return dfs(t, i - 1, j) || dfs(t, i + 1, j) || dfs(t, i, j - 1) || dfs(t, i, j + 1);
    }
    int swimInWater(vector<vector<int>>& grid) {
        this->grid = grid;
        this->N = grid.size();
        //Linear Search
        // for (int t = 0; t <= INF; t++)
        // {
        //     //reset seen
        //     memset(seen, 0, sizeof(seen));
        //     if (dfs(t, 0, 0)) return t;
        // }
        //Binary Search
        int lo = 0, hi = INF, mid = 0;
        while (lo < hi)
        {
            // mid = lo + (hi - lo) / 2;
            mid = lo + (hi - lo) / 2;
            memset(seen, 0, sizeof(seen));
            if (dfs(mid,0,0))
            {
                hi = mid;
            }
            else 
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
