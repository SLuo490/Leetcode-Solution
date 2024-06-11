#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freqMap; 
        for (int num : arr1) {
            freqMap[num]++; 
        }

        vector<int> res; 
        for (int i = 0; i < arr2.size(); i++) {
            while (freqMap[arr2[i]]--) {
                res.push_back(arr2[i]); 
            }
        }

        sort(arr1.begin(), arr1.end()); 

        for (int i = 0; i < arr1.size(); i++) {
            if (freqMap[arr1[i]] > 0) {
                res.push_back(arr1[i]); 
            }
        } 
        
        return res; 
    }
};



/*
    arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]

    - not in both array: [7, 19]
    
    
    - relative order:
    - all the 2s will appear before the 1s
    - all the 1s will appear before the 4s
    ...
    - number not in arr2 will appear in the end as sorted 


    2: 3
    3: 2
    1: 1
    4: 1
    6: 1
    7: 1
    9: 1
    19: 1

    [2, 2, 2, 1, 4, 3, 3, 9, 6]

    loop through arr2
        for each number check the frequency of it appearing in the map and add the number it appears into result
            decrement the map
            erase from map
        add the rest of the number in map into array sort then add it towards the end


*/

int main() {
  Solution solution; 
  vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19}; 
  vector<int> arr2 = {2,1,4,3,9,6}; 
  vector<int> res = solution.relativeSortArray(arr1, arr2); 
  for (int num : res) {
    cout << num << " "; 
  }
  cout << endl; 
  return 0; 
}
