/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        // USING NPOS
        if (haystack.length() == 0 && needle.length() == 0) return 0;
        
        int found = haystack.find(needle);
        
        if (found != string::npos) {
            return found;
        } else {
            return -1;
        }
        
//         Two Pointer Approach
// 		int needle_len = needle.length();
// 		int haystack_len = haystack.length();
// 		if(needle_len==0){
// 			return 0;
// 		}
// 		int j = 0;
// 		for(int i = 0 ; i < haystack_len ; i++){

//             //increment haystack until needle matches haystack
// 			if(haystack[i] == needle[j]){
// 				j++;
// 			}else{
//                 //increment i, but not j
// 				i = i-j;
// 				j = 0;
// 			}
//             //returns the index when needle matches haystack
// 			if(j==needle_len){
// 				return i - j +1 ;
// 			}
// 		}
// 		return -1;
    }
};
