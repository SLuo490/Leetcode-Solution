/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"
*/

class Solution {
public:
    //makes it slow
//     bool isVowel(char ch) {
//         unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
//         //if vowel is contained in set return true
//         if (vowel.find(ch) != vowel.end()) {
//             return true;
//         }
//         return false;
//     }
    
    string reverseVowels(string s) {
//         int end = s.length() - 1;
//         int start = 0;
//         int size = s.length();
        
//         while (start < size && end >= 0 && start <= end) {
//             //if both start and end is a vowel then swap
//             if (isVowel(s[start]) && isVowel(s[end])) {
//                 swap(s[start], s[end]);
//                 start++;
//                 end--;
//             }
            
//             //if start is not a vowel, then increment until it is a vowel
//             while (start < size && !isVowel(s[start])) {
//                 start++;
//             }
            
//             //if end is not a vowel, then decrement until it is a vowel
//             while (end >= 0 && !isVowel(s[end])) {
//                 end--;
//             }
//         }
//         return s;
        
        vector<int>v;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                v.push_back(i);
            }
        }
        //"leetcode"
        //v = {1, 2, 5, 7} //index in where vowels appear in string
        
      //if vector is empty, then there is no vowels
        if(v.empty())
        {
            return s;
        }
      
      
        /*
            v = {1, 2, 5, 7}
            //size of vector
            i = 0
            j = 3
            
            swap element at index 1 and 7 
            "leetcode
              -     -
            
            i = 1
            j = 2
            
            swap element at index 2 and 5
            "leotcede"
               -  -
          
        */
        int i=0,j=v.size()-1;
        while(j>i)
        {
            swap(s[v[i]],s[v[j]]);
            j--;
            i++;
        }
        return s;
    }
};
