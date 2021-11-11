class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 2) return 1;
    
        vector<int> dp(n + 1, 0); 
        dp[1] = 1; 
        dp[2] = 1; 
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; 
        }
            
        return dp[n];

    }
};

/*
n = 4
dp = [0,1,1,0,0]

i = 3
dp[3] = dp[2] + dp[1] + d[0]
dp[3] = 1 + 1 + 0
dp[3] = 2

dp = [0,1,1,2,0]

i = 4
dp[4] = dp[3] + dp[2] + d[1]
dp[4] = 2 + 1 + 1
dp[4] = 4

dp = [0,1,1,2,4]

return dp[4] = 4

*/
