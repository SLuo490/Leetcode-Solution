/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string. You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        //initialize a carry, length of num1 and 2
        //initialize a string res
        //loop through string of num1 and num2
            //if condition of length num1
                //add sum by subtracting index i by char 0 and decrement length of num1
            //if condition of length num2
                //add sum by subtracting index j by char 0 and decrement length of num2
            //calculate the carry and sum
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ret = "";
        
        while (i >= 0 || j >= 0 || carry)
        {
            //why does sum need to be inside loop? Because sum needs to be updated inside the loop?
            int sum = 0;
            if (i >= 0) 
            {
                //num1[i] - '0'
                    //'9' - '0' = ascii(9) - ascii(0) = 57 - 48 = 9
                sum += (num1[i] - '0');
                i--;
            }
            if (j >= 0)
            {
                sum += (num2[j] - '0');
                j--;
            }
            //compute the sum and carry
                //6 + 7 = 13
                //sum += carry = 13
                //carry = 13 / 10 = 1
                    //takes the floor of 1.3
                //sum = 13 % 10 = 3
                //ret = "3"
            //...
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            //add it to ret
            ret = ret + to_string(sum);
        }
        //"335"
        reverse(ret.begin(),ret.end());
        //"533"
        return ret;
    }
};
