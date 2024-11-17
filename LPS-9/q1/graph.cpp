#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

bool is_safe_position(vector<vector<int>>& grid, int row, int col, int rows) {
    if ((row + col) % 3 == 0) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        if (grid[i][col] == 1) {
            return false;
        }
    }
    return true;
}

void solve_nqueens(vector<vector<int>>& grid, int &solutions, int queens, int rows, int cols, int current_row) {
    if (current_row == queens) {
        solutions++;
        return;
    }
    for (int col = 0; col < cols; col++) {
        if (is_safe_position(grid, current_row, col, rows)) {
            grid[current_row][col] = 1;
            solve_nqueens(grid, solutions, queens, rows, cols, current_row + 1);
            grid[current_row][col] = 0;
        }
    }
}

int main() {
    ofstream file("nqueens_times.csv");
    file << "Board Size,Time (microseconds)\n";

    // Test different board sizes
    for (int size = 4; size <= 12; size++) {  // Reduced maximum size due to exponential growth
        vector<vector<int>> board(size, vector<int>(size, 0));
        int total_solutions = 0;
        
        // Multiple runs for stable measurements
        vector<long long> times;
        const int runs = 3;  // Reduced runs due to complexity
        
        for (int run = 0; run < runs; run++) {
            auto start = high_resolution_clock::now();
            solve_nqueens(board, total_solutions, size, size, size, 0);
            auto stop = high_resolution_clock::now();
            times.push_back(duration_cast<microseconds>(stop - start).count());
        }
        
        // Use median time
        sort(times.begin(), times.end());
        long long median_time = times[runs/2];
        
        file << size << "," << median_time << "\n";
    }

    file.close();
    return 0;
}