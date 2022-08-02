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
    for (int row = 0; row < board.size(); row+=3) {
        // traverse to 3
        for (int col = 0; col < board.size(); col+=3) {
            set<char> seen; 
            for (int rowx = row; rowx < row + 3; rowx++) {
                for (int coly = col; coly < row + 3; coly++) {
                    char currentChar = board[rowx][coly]; 
                    if (seen.find(currentChar) != seen.end()) {
                        return false; 
                    }

                    if (currentChar == ',' || currentChar == '.') {
                        continue; 
                    } else {
                        seen.insert(currentChar); 
                    }
                }
            }
            seen.clear(); 
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board {
         {'5','3','.','.','7','.','.','.','.'},
         {'6','2','.','1','9','5','.','.','.'},
         {'.','9','9','.','.','.','.','6','.'},
         {'8','.','.','.','6','.','.','.','3'},
         {'4','.','.','8','.','3','.','.','1'},
         {'7','.','.','.','2','.','.','.','6'},
         {'.','6','.','.','.','.','2','8','.'},
         {'.','.','.','4','1','9','.','.','5'},
         {'.','.','.','.','8','.','.','7','9'}
    }; 

    vector<vector<char>> board2 = 
        {
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}
        }; 

    bool res = isValidSudoku(board2); 

    if (res == true) {
        cout << "True" << endl; 
    } else {
        cout << "False" << endl;
    } 

    return 0; 
}