#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;
using namespace std::chrono;

int count_digits(int number) {
    int digit_count = 0;
    while (number > 0) {
        digit_count++;
        number /= 10;
    }
    return digit_count;
}

bool are_digits_unique(int x, int y) {
    int x_size = count_digits(x);
    int y_size = count_digits(y);
    int digits_x[x_size];
    int digits_y[y_size];
    int remainder, idx = 0;
    
    while (x > 0) {
        remainder = x % 10;
        digits_x[idx++] = remainder;
        x /= 10;
    }
    idx = 0;
    while (y > 0) {
        remainder = y % 10;
        digits_y[idx++] = remainder;
        y /= 10;
    }
    
    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {
            if (digits_x[i] == digits_y[j]) {
                return false;
            }
        }
    }
    return true;
}



void find_largest_unique_set(vector<int>& numbers) {
    int size = numbers.size();
    int max_count = 0;
    vector<int> largest_set;
    
    for (int i = 0; i < size; i++) {
        vector<int> current_set = {numbers[i]};
        
        for (int j = i + 1; j < size; j++) {
            bool is_unique = true;
            for (int k = 0; k < current_set.size(); k++) {
                if (!are_digits_unique(current_set[k], numbers[j])) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                current_set.push_back(numbers[j]);
            }
        }
        
        if (current_set.size() > max_count) {
            max_count = current_set.size();
            largest_set = current_set;
        }
    }
}

int main() {
    ofstream file("unique_digits_times.csv");
    file << "Input Size,Time (microseconds)\n";

    // Random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 9999);

    // Test different input sizes
    for (int size = 10; size <= 200; size += 10) {
        vector<int> numbers;
        
        // Generate random numbers
        for (int i = 0; i < size; i++) {
            numbers.push_back(dis(gen));
        }
        sort(numbers.begin(), numbers.end());

        // Multiple runs for stable measurements
        vector<long long> times;
        const int runs = 5;
        
        for (int run = 0; run < runs; run++) {
            auto start = high_resolution_clock::now();
            find_largest_unique_set(numbers);
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