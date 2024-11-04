#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

bool inc(const string& s1, const string& s2) {
    if (s1[0] != s2[0]) return false;
    for (size_t k = 2; k < s1.length(); k++) {
        if ((s1[k-1] - s2[k-1]) <= (s1[k-2] - s2[k-2])) {
            return false;
        }
    }
    return true;
}

bool dec(const string& s1, const string& s2) {
    if (s1[0] != s2[0]) return false;
    for (size_t k = 2; k < s1.length(); k++) {
        if ((s1[k-1] - s2[k-1]) >= (s1[k-2] - s2[k-2])) {
            return false;
        }
    }
    return true;
}

void check(const string& text, const string& pat) {
    int t = text.length();
    int p = pat.length();
    
    for (int i = 0; i <= t - p; i++) {
        string temp = text.substr(i, p);
        if (temp == pat) {
            continue;
        } else if (inc(temp, pat)) {
            continue;
        } else if (dec(temp, pat)) {
            continue;
        }
    }
}

int main() {
    ofstream file("string_categorization_times.csv");
    file << "Text Length,Pattern Length,Time (microseconds)\n";

    // Generate more appropriate test cases
    for (int text_length = 100; text_length <= 1000; text_length += 100) {
        for (int pattern_length = 10; pattern_length <= min(100, text_length/2); pattern_length += 10) {
            string text(text_length, 'A');
            string pattern(pattern_length, 'A');
            
            // Add variations to create more realistic test cases
            for (int i = 0; i < text_length; i += 3) {
                text[i] = char('A' + (i % 26));
            }
            
            // Multiple runs to get stable measurements
            vector<long long> times;
            for (int run = 0; run < 5; run++) {
                auto start = high_resolution_clock::now();
                check(text, pattern);
                auto stop = high_resolution_clock::now();
                times.push_back(duration_cast<microseconds>(stop - start).count());
            }
            
            // Use median time to avoid outliers
            sort(times.begin(), times.end());
            long long median_time = times[2];
            
            file << text_length << "," << pattern_length << "," << median_time << "\n";
        }
    }

    file.close();
    return 0;
}