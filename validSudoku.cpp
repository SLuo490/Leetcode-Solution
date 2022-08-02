#include <bits/stdc++.h>
#include <vector> 

using namespace std; 

bool isValidRow(vector<vector<char>>& board); 
bool isValidCol(vector<vector<char>>& board); 
bool isValidSquare(vector<vector<char>>& board); 

bool isValidSudoku(vector<vector<char>>& board) {
    bool validRow = isValidRow(board); 
    bool validCol = isValidCol(board); 
    bool validSquare = isValidSquare(board); 

    return validRow && validCol && validSquare ? true : false; 
}

// function to check all rows in board
bool isValidRow (vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        set<char> seen; 
        for (int j = 0; j < board[i].size(); j++) {
            char currentChar = board[i][j]; 
            if (seen.find(currentChar) != seen.end()) {
                return false; 
            }

            if (currentChar == ',' || currentChar == '.') {
                continue; 
            } else {
                seen.insert(currentChar); 
            }
        }
        seen.clear(); 
    }
    return true; 
}

// function to check all cols in board
bool isValidCol (vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        set<char> seen; 
        for (int j = 0; j < board[i].size(); j++) {
            char currentChar = board[j][i]; 
            if (seen.find(currentChar) != seen.end()) {
                return false; 
            }

            if (currentChar == ',' || currentChar == '.') {
                continue; 
            } else {
                seen.insert(currentChar); 
            }
        }
        seen.clear(); 
    }
    return true; 
}

// function to check all 3x3 squares in board
bool isValidSquare(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        // traverse to 3
        for (int j = 0; j < board.size(); j++) {

        }
    }
    return false; 
}

/*
      0 1 2 3 4 5 
    0 0 0 0 0 0 0
    1 0 0 0 0 0 0
    2 0 0 0 0 0 0
    3 0 0 0 0 0 0
    4 0 0 0 0 0 0
    5 0 0 0 0 0 0
*/


int main() {
    vector<vector<char>> board {
         {'5','3','.','.','7','.','.','.','.'},
         {'6','.','.','1','9','5','.','.','.'},
         {'.','9','8','.','.','.','.','6','.'},
         {'8','.','.','.','6','.','.','.','3'},
         {'4','.','.','8','.','3','.','.','1'},
         {'7','.','.','.','2','.','.','.','6'},
         {'.','6','.','.','.','.','2','8','.'},
         {'.','.','.','4','1','9','.','.','5'},
         {'.','.','.','.','8','.','.','7','9'}
    }; 

    bool res = isValidSquare(board); 

    if (res == true) {
        cout << "True" << endl; 
    } else {
        cout << "False" << endl;
    } 

    return 0; 
}