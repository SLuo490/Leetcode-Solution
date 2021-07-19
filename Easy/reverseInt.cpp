class Solution {
public:
    /*
        123
        remainder = 0    
        x = 123
        res = 0
        --------------
        remainder = 123 % 10 => remainder = 3
        x = 123 / 10 => 12.3 => x = 12
        res = (0 * 10) + remainder => res = 3
        --------------
        remainder = 12 % 10 => remainder = 2
        x = 12 / 10 => 1.2 => x = 1
        res = (3 * 10) + remainder => 30 + 2 => res = 32
        --------------
        remainder = 1 % 10 => remainder = 1
        x = 1 / 10 => .1 => x = 0
        res = (32 * 10) + remainder => 320 + 1 -> res - 321
        
        return 321
    */
    int reverse(int x) {
        int res = 0;
        int remainder = 0;
        while ( x != 0) {
            //handle boundary condition
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }
            //123 % 10 -> 3
            remainder = x % 10;
            //123 / 10 -> 12
            x = x/10;
            res = (res * 10) + remainder;
        }
        return res;
    }
};
