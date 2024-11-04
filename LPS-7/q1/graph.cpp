#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

void naiveStringMatch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    // Force worst-case scenario
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
    }
}

int main() {
    ofstream file("naive_pattern_times.csv");
    file << "Text Length,Pattern Length,Time (microseconds)\n";

    // Generate test cases that better show m×n relationship
    for (int text_length = 1000; text_length <= 10000; text_length += 1000) {
        for (int pattern_length = 100; pattern_length <= min(1000, text_length/2); pattern_length += 100) {
            // Create worst-case scenario strings
            // Pattern of all 'A's and text of all 'A's with last character 'B'
            string text(text_length, 'A');
            string pattern(pattern_length, 'A');
            text[text_length-1] = 'B';  // Force comparison till end

            // Run multiple times to get stable measurements
            vector<long long> timings;
            int runs = 5;
            
            for (int run = 0; run < runs; run++) {
                auto start = high_resolution_clock::now();
                naiveStringMatch(text, pattern);
                auto stop = high_resolution_clock::now();
                timings.push_back(duration_cast<microseconds>(stop - start).count());
            }

            // Calculate median time to avoid outliers
            sort(timings.begin(), timings.end());
            long long median_time = timings[runs/2];

            file << text_length << "," << pattern_length << "," << median_time << "\n";
        }
    }

    file.close();
    return 0;
}