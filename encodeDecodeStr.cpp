#include <bits/stdc++.h>

using namespace std; 

string encode (vector<string>& strs) {
    string res = ""; 
    for (string s : strs) {
        res += to_string(s.length()) + "#" + s; 
    }
    return res; 
}

vector<string> decode (string str) {
    vector<string> res; 
    int i = 0; 

    while (i < str.length()) {
        int j = i; 
        // while the current element is not the delimiter increment j
        while (str[j] != '#') {
            j++; 
        }
        
        // get the length of the string
        // substring (starting index, length of the string to cut)
        int length = stoi(str.substr(i, j - i)); 
        // get the new string skipping the number and #
        string newStr = str.substr(j + 1, length); 
        res.push_back(newStr);
        // increment i to the next starting number's length 
        i = j + 1 + length; 
    }
    return res; 
}

int main() {
    vector<string> strs = {"63/Rc","h","BmI3FS~J9#vmk","7uBZ?7*/","24h+X","O "}; 
    string s = encode(strs); 
    cout << s << endl; 
    vector<string> decodedStrs = decode(s); 
    for (int i = 0; i < decodedStrs.size(); i++) {
        cout << decodedStrs[i] << endl; 
    } 
    return 0; 
}