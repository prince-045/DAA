#include <iostream>
#include <vector>

using namespace std;

// Function to print the board
void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "Q ";  // Queen is placed
            else
                cout << ". ";  // Empty space
        }
        cout << endl;
    }
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false; // There is already a queen in the column
        }
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false; // There is already a queen in the upper-left diagonal
        }
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false; // There is already a queen in the upper-right diagonal
        }
    }

    return true;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        printBoard(board, n);  // All queens are placed, print the solution
        return true;
    }

    bool res = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place queen
            res = solveNQueens(board, row + 1, n) || res;  // Recur to place rest of the queens
            board[row][col] = 0;  // Backtrack (remove queen)
        }
    }
    return res;  // Return true if any solution is found
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    // Create an empty chessboard of size n x n
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists!" << endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to print the positions of queens (dimensions)
// void printDimensions(const vector<int>& board, int n) {
//     cout << "Positions of queens: ";
//     for (int i = 0; i < n; i++) {
//         cout << "(" << i << ", " << board[i] << ") ";
//     }
//     cout << endl;
// }

// // Check if it's safe to place a queen at board[row][col]
// bool isSafe(const vector<int>& board, int row, int col) {
//     for (int i = 0; i < row; i++) {
//         // Check if the column or diagonals are under attack
//         if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
//             return false;
//         }
//     }
//     return true;
// }

// // Backtracking function to solve the N-Queens problem
// bool solveNQueens(vector<int>& board, int row, int n) {
//     if (row == n) {
//         printDimensions(board, n);  // Print the positions (dimensions) of queens
//         return true;
//     }

//     bool res = false;
//     for (int col = 0; col < n; col++) {
//         if (isSafe(board, row, col)) {
//             board[row] = col;  // Place queen at (row, col)
//             res = solveNQueens(board, row + 1, n) || res;  // Recur to place the rest of the queens
//         }
//     }
//     return res;  // Return true if any solution is found
// }

// int main() {
//     int n;
//     cout << "Enter the number of queens: ";
//     cin >> n;

//     // Create a board represented by a vector, where board[i] = column of the queen in row i
//     vector<int> board(n, -1);  // Initialize all positions to -1 (no queen placed)

//     if (!solveNQueens(board, 0, n)) {
//         cout << "No solution exists!" << endl;
//     }

//     return 0;
// }

