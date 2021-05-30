class Solution {
public:
    bool isValid(string s) {
        //create a stack
        stack<char> stack;
        //loop through string s
        for (auto i : s)
        {
            //push i to stack if it is (, {, or [
            if (i == '(' || i == '{' || i == '[')
            {
                //push it to stack
                stack.push(i);
            }
            else 
            {
                //check if i is the closing character of top 
                if (stack.empty() || (stack.top() == '(' && i != ')') || (stack.top() == '{' && i != '}') || (stack.top() == '[' && i != ']'))
                {
                    return false;
                }
                    stack.pop();

            }
        }
        //return it stack is empty
        return stack.empty();
    }
};
