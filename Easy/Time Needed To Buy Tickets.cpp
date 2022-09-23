#include <bits/stdc++.h>
using namespace std;

/*
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

eturn the time taken for the person at position k (0-indexed) to finish buying tickets.

 
Example 1:
Input: tickets = [2,3,2], k = 2
Output: 6
Explanation: 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.

Example 2:
Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0; 
        while (tickets[k] != 0) {
            for (int i = 0; i < tickets.size(); i++) {
                if (tickets[i] == 0) {
                    continue; 
                } else {
                    tickets[i] -= 1; 
                    res++; 
                }
                
                if (tickets[k] == 0) break; 
            }
        }
        return res; 
    }
};


/*
     0 1 2
    [2,3,2] k = 2
    
    while (the number at k's position is not 0)
        traverse through the tickets
            if the number is 0 skip
            else
                decrement number 
                increment res
    return res
    
     0 1 2 3
    [1,2,3,4] k = 2
    
    [0, 1, 2, 3] res = 4
    [0, 0, 1, 2] res = 7
    [0, 0, 0]
*/

int main()
{
  return 0;
}