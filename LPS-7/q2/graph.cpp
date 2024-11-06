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

    // Much larger increments for clearer complexity visualization
    for (int text_length = 5000; text_length <= 50000; text_length += 5000) {  // 5K to 50K
        for (int pattern_length = 500; pattern_length <= text_length/4; pattern_length += 500) {  // 500 to text_length/4
            string text, pattern;
            
            // Generate text with variations
            for (int i = 0; i < text_length; i++) {
                if (i % 3 == 0) text += 'A';
                else if (i % 3 == 1) text += 'B';
                else text += 'C';
            }
            
            // Generate pattern
            for (int i = 0; i < pattern_length; i++) {
                pattern += char('A' + (i % 3));
            }
            
            // Fewer runs for larger sizes
            vector<long long> times;
            const int runs = 5;  // Reduced runs due to much larger sizes
            
            for (int run = 0; run < runs; run++) {
                auto start = high_resolution_clock::now();
                check(text, pattern);
                auto stop = high_resolution_clock::now();
                times.push_back(duration_cast<microseconds>(stop - start).count());
            }
            
            // Use median time
            sort(times.begin(), times.end());
            long long median_time = times[runs/2];
            
            file << text_length << "," << pattern_length << "," << median_time << "\n";
        }
    }

    file.close();
    return 0;
}