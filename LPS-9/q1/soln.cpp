#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_safe_position(vector<vector<int>>& grid, int row, int col, int rows) {
    int i;
    if ((row + col) % 3 == 0) {
        return false;
    }
    for (i = 0; i < rows; i++) {
        if (grid[i][col] == 1) {
            return false;
        }
    }
    return true;
}

void solve_nqueens(vector<vector<int>>& grid, int &solutions, int queens, int rows, int cols, int current_row) {
    int col;
    if (current_row == queens) {
        solutions++;
        return;
    }
    for (col = 0; col < cols; col++) {
        if (is_safe_position(grid, current_row, col, rows)) {
            grid[current_row][col] = 1;
            solve_nqueens(grid, solutions, queens, rows, cols, current_row + 1);
            grid[current_row][col] = 0;
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> board(rows, vector<int>(cols, 0));
    int total_solutions = 0;
    int queens = min(rows, cols);
    solve_nqueens(board, total_solutions, queens, rows, cols, 0);
    cout << total_solutions << endl;
    
    return 0;
}