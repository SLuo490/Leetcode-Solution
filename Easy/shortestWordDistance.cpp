/*
Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Example 1:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3

Example 2:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

/*
  Time Complexity: O(N * M)	
  Space Complexity: O(N)
*/
int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
	if (wordsDict.size() < 2) return 0; 
	vector<pair<int,string>> dist; 
	int minDist = INT_MAX; 


  	// add the idx of the current word to dist vector
	for (int idx = 0; idx < wordsDict.size(); idx++) {
    	string currWord = wordsDict[idx]; 
    	if (word1 == currWord) {
      		dist.push_back({idx, currWord}); 
   	 	}
		if (word2 == currWord) {
      		dist.push_back({idx, currWord}); 
    	}
  	}

  	// calculate the minimum distance
	for (int idx = 1; idx < dist.size(); idx++) {
		if (dist[idx].second != dist[idx - 1].second) {
			minDist = min(minDist, dist[idx].first - dist[idx - 1].first); 
		}
	}
	return minDist; 
}

/*
  Time Complexity: O(N * M)	where M is the length of word1 + length of word2
  Space Complexity: O(1)
*/
int shortestDistance2(vector<string>& wordsDict, string word1, string word2) {
	if (wordsDict.size() < 2) return 0; 
	int minDist = INT_MAX; 
	int leftIdx = -1; 
	int rightIdx = -1; 
	
	for (int idx = 0; idx < wordsDict.size(); idx++) {
		string currWord = wordsDict[idx]; 
		if (word1 == currWord) {
			leftIdx = idx; 
		} else if (word2 == currWord) {
			rightIdx = idx; 
		}
		
		if (leftIdx != -1 && rightIdx != -1) {
			minDist = min(minDist, abs(rightIdx - leftIdx)); 
		}
	}
			
	return minDist; 
}

int main() {
	// vector<string> wordsDict {"practice", "makes", "perfect", "coding", "makes"};
	// string word1 = "coding";
	// string word2 = "practice";
	

	vector<string> wordsDict {"a", "c", "a", "b"}; 
	string word1 = "a";
	string word2 = "b";
	cout << shortestDistance2(wordsDict, word1, word2) << endl;
}
