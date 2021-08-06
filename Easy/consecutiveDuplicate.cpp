/*
Given a string s, consisting of "X" and "Y"s, delete the minimum number of characters such that there's no consecutive "X" and no consecutive "Y".

Example 1
Input
s = "YYYXYXX"
Output
"YXYX"
Explanation
One solution is to delete the first two "Y"s and the last "X".
*/



//O(n) Time and Space
string solve(string s) {
    int j = 0;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        j = i + 1;
        if (s[i]!=s[j]) {
            res += s[i];
        }
    }
    return res;
}
