#include <bits/stdc++.h>
using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    // calculate the difference between the sum of A and B
    int diff = 0, sumA = 0, sumB = 0;
    for (int a : A) sumA += a;
    for (int b : B) sumB += b;
    diff = (sumA - sumB) / 2; 

    // initialize a set to check if Alice has the desired candy 
    set<int> s (begin(A), end(A)); 
    
    for (int b : B) {
        if (s.count(b + diff)) {
            return {b + diff, b}; 
        }
    }
    return {}; 
}

/*
    A: [1,2,5]
    B: [2,4]

    A = 8
    B = 6

    diff = 8 - 6 = 2 / 2 = 1

    set S = {1,2,5}

        b = 2
        2 + 1 = 3

        b = 4
        4 + 1 = 5 == true

        return {4 + 1, 4}
*/

int main() {
    vector<int> A = {1, 2, 5}, B = {2, 4};
    vector<int> res = fairCandySwap(A, B);
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
}