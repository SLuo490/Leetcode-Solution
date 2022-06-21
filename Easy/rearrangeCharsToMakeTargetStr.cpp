/*
You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.
Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

Example 1:
Input: s = "ilovecodingonleetcode", target = "code"
Output: 2
Explanation:
For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
We can make at most two copies of "code", so we return 2.

Example 2:
Input: s = "abcba", target = "abc"
Output: 1
Explanation:
We can make one copy of "abc" by taking the letters at indices 0, 1, and 2.
We can make at most one copy of "abc", so we return 1.
Note that while there is an extra 'a' and 'b' at indices 3 and 4, we cannot reuse the letter 'c' at index 2, so we cannot make a second copy of "abc".
*/

/*
    s: "abbaccaddaeea"
    target: "aaaaa"
    
    targetmap: {a:5}
    sMap: {a:5, b: 2, ....}
    res = INT_MAX
    res = min(INT_MAX, (5/5)) = min(INT_MAX, 1) => 1
    return 1
*/

class Solution {
public:
    /*
        Time Complexity: O(N)
        Space Complexity: O(2N) -> O(N)
    */
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> sMap; 
        unordered_map<char,int> tMap; 
        
        for (auto ch : s) sMap[ch]++; 
        for (auto ch : target) tMap[ch]++; 
        
        int res = INT_MAX;
        
        // traverse the target Map and calculate the minimum frequency ratio 
        for (auto it : tMap) {
            res = min(res, sMap[it.first] / it.second);  
        }
        return res; 
    }
};
