/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/

class Solution {
public:
    //helper function to calculate the symbol(addition, subtraction, multiplication and division)
    int eval(string tokens, int a, int b)
    {
        if (tokens == "+") return a + b;
        if (tokens == "-") return a - b;
        if (tokens == "*") return a * b;
        if (tokens == "/") return a / b;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        //create int a, b, 
        int a, b, temp;
        //create a vector that is a stack
        vector<int> stk;
        //loop through tokens
        for (auto x : tokens)
        {
            //if the char is x, +, -, /
            if (x == "+" || x == "-" || x == "*" || x == "/")
            {
                //set b to the first item
                b = stk.back();
                //pop item
                stk.pop_back();
                //set a to the next item
                a = stk.back();
                //pop item
                stk.pop_back();
                //evaluate the total
                temp = eval(x, a, b);
                //push it to stk
                stk.push_back(temp);
            }
            else
            {
                //push it to stk if it is a number
                stk.push_back(stoi(x));
            }
        }
        //return first item in stack
        return stk.front();
    }
};
