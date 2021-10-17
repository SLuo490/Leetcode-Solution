/*
There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
Alice and Bob cannot remove pieces from the edge of the line.
If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.

 

Example 1:
Input: colors = "AAABABB"
Output: true

Explanation:
AAABABB -> AABABB
Alice moves first.
She removes the second 'A' from the left since that is the only 'A' whose neighbors are both 'A'.

Now it's Bob's turn.
Bob cannot make a move on his turn since there are no 'B's whose neighbors are both 'B'.
Thus, Alice wins, so return true.

Example 2:
Input: colors = "AA"
Output: false
Explanation:
Alice has her turn first.
There are only two 'A's and both are on the edge of the line, so she cannot move on her turn.
Thus, Bob wins, so return false.
*/


class Solution {
public:
    bool winnerOfGame(string colors) {
        int res = 0;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                //if there is "AAA", then we can increment res by 1, else decrement by 1
                if (colors[i] == 'A') {
                    res++;
                } else {
                    res--;
                }
            }
            
        }
        return res > 0;
    }
};
