class Solution {
public:
    int fib(int n) {
        //first two number
        if (n <= 1) {
            return  n;
        }
        if (n == 2) {
            return 1;
        }
        int current = 0;
        int previous = 1;
        int previous2 = 1;
        //loop starting at 3 
        for (int i = 3; i <= n; i++) {
            //iterativly calculate fib(n)
            /*
                ex) fib(6)
                    curr = 0
                    prev = 1
                    prev2 = 1
                    ----------
                    i = 3
                    curr = 2
                    prev2 = 1
                    prev = 2
                    ----------
                    i = 4
                    curr = 3
                    prev2 = 2
                    prev = 3
                    ----------
                    i = 5
                    curr = 5
                    prev2 = 3
                    prev = 5
                    ----------
                    i = 6
                    curr = 8
                    prev2 = 5
                    prev = 8
                    return curr = 8
            */
            current = previous + previous2;
            previous2 = previous;
            previous = current;
        }
        return current;
    }
};
