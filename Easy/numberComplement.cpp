/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

Example 1:
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/



class Solution {
public:
    int findComplement(int num) {
        if (num == 1) return 0; 
        
        //convert int to binary
        string binary = decimalToBinary(num); 
    
        //complement the binary
        string comp = complement(binary); 

        
        //convert complement to decimal
        int res = 0; 
        int j = 0; 
        for (int i = comp.length() - 1; i > 0; i--) {
            if (comp[i] == '1') {
                res += pow(2, j); 
            }
            j++; 
        }
                
        return res; 
    }
    
    string decimalToBinary(int num) {
        string res = "";
        
        while (num > 0) {
            res = to_string(num % 2) + res; 
            num /= 2; 
        }
        return res; 
    }
    
    string complement(string binary) {
        string comp = ""; 
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '0') {
                comp += '1'; 
            } else if (binary[i] == '1') {
                comp += '0';
            }
        }
        return comp; 
    }
};
