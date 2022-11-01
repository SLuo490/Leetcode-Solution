#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Slow: Time: O(N), Space: O(1)
    bool checkPerfectNumber(int num) {
        int sum = 0; 
        
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i; 
            }
        }
        return sum == num; 
    }
    
    // Faster: Time: O(sqrt(n)) Space: O(1)
    bool checkPerfectNumber(int num) {
        if (num <= 0) return false;
        
        int sum = 0; 
        for (int i = 1; i * i <= num; i++) {
            // if i is divisible by num
            if (num % i == 0) {
                sum += i; 
                
                if (i * i != num) {
                    sum += num / i; 
                }
            }
        }
        return sum - num == num; 
    }
};

/*
    28 
    
    1 + 2 + 4 + 7 + 14 = 

    28 / 2 = 14

*/


int main()
{
  return 0;
}