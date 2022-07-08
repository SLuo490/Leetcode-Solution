/*
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Example 1:
Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

Example 2:
Input: paragraph = "a.", banned = []
Output: "a"
*/

#include <iostream>
#include <string> 
#include <vector>
#include <set>
#include <unordered_map>

using namespace std; 

// Time: O(N + M + K) N is the length of paragraph, M is the length of banned, K is the length of the most common word
// Space: O(M + K) M and N is the set of banned words 
string mostCommonWord(string paragraph, vector<string>& banned) {
    string currWord = ""; 
    int maxOccurr = 0; 
    unordered_map<string, int> wordFreq; 
    set<char> skipChar = {' ', '!', '?', '.', ',', '\'', '\"', ';'};
    set<string> bannedWords; 
    
    // keep track of the banned words using a set 
    for (string word : banned) bannedWords.insert(word);

    for (int i = 0; i <= paragraph.length(); i++) {
        char currChar = tolower(paragraph[i]);

        // if the current word is empty and the current character is contained in skipChar then skip it and continue
        if (currWord == "" && skipChar.count(currChar) == 1) continue;

        // if the curr character is contained in skipChar and is not a banned word
        // add it to map and reset currWord and update maxOccurr
        if ((skipChar.count(currChar) == 1 || i == paragraph.length()) && bannedWords.find(currWord) == bannedWords.end()) {
            wordFreq[currWord]++;
            maxOccurr = max(maxOccurr, wordFreq[currWord]);
            currWord = "";
        } else {
            // build the current word
            currWord += currChar;
        }

        // if the current word is banned word and next character is contained in skipChar then reset currWord
        // handles edge case where banned word = ["abc", "abcd"] and current word is "abc" and next character is "d"
        // this will add d to current word and check to see if the current word is in banned words
        if (bannedWords.find(currWord) != bannedWords.end() && skipChar.count(paragraph[i + 1]) == 1) {
            currWord = "";
        }
    }

    string ans = ""; 
    for (auto word : wordFreq) {
        if (word.second == maxOccurr) {
            ans = word.first;
        }
    }
    return ans; 
}

int main() {
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << mostCommonWord(paragraph, banned) << endl;

    string paragraph2 = "a.";
    vector<string> banned2 = {};
    cout << mostCommonWord(paragraph2, banned2) << endl;

    return 0; 
}