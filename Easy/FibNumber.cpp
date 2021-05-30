class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return  n;
        }
        if (n == 2) {
            return 1;
        }
        int current = 0;
        int previous = 1;
        int previous2 = 1;
        for (int i = 3; i <= n; i++) {
            current = previous + previous2;
            previous2 = previous;
            previous = current;
        }
        return current;
    }
};
