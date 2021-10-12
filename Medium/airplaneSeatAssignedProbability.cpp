/*
n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:
Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?

 
Example 1:
Input: n = 1
Output: 1.00000
Explanation: The first person can only get the first seat.

Example 2:
Input: n = 2
Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).

*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1;
        return 0.5;
        // return n == 1 ? 1 : 0.5;
    }
};

/*
The answer is 1/2 if n > 1. 

Let say there are 20 seats. The first person loses his ticket, so he chooses a random seat. The second person goes to his seat, the third person finds his seat taken, so he goes to a random seat. This goes on until the 19th person has two choices to make. Either he goes to his seat and it is not taken, or he chooses a random seat of the two (1/2). The last person has his seat determined since there are only 1 seat left (n == 1 -> 100 percent)
*/
