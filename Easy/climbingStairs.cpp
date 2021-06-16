/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
    int climbStairs(int n) {
        
        //fib but start with 1
        //1, 1, 2, 3
        
        if (n <= 1) return 1;
        int current = 0;
        int prev = 1;
        int prev2 = 1;
        
        for (int i = 2; i <= n; i++)
        {
            current = prev + prev2;
            prev2 = prev;
            prev = current;
        }
        return current;
        
        //n = 3
        /*
        current = 0
        prev = 1
        prev2 = 1
        
        i = 2
        current = 2;
        prev2 = 1
        prev = 2
        
        i = 3
        current = 3
        prev2 = 2
        prev = 3
        */
    }
};
