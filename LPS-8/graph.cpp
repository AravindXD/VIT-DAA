#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

void sortarr(vector<string>& act, vector<int>& s, vector<int>& f) {
    int n = act.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(f[i] > f[j]) {
                swap(f[i], f[j]);
                swap(s[i], s[j]);
                swap(act[i], act[j]);
            }
        }
    }
}

void activitySelection(vector<string>& act, vector<int>& s, vector<int>& f) {
    sortarr(act, s, f);
    int x = 0;
    for(int i = 1; i < act.size(); i++) {
        if(s[i] >= f[x]) {
            x = i;
        }
    }
}

int main() {
    ofstream file("activity_selection_times.csv");
    file << "Size,Time (microseconds)\n";

    // Test different sizes
    for(int n = 10000; n <= 20000; n += 1000) {
        vector<string> act(n);
        vector<int> s(n);
        vector<int> f(n);

        // Generate test data
        for(int i = 0; i < n; i++) {
            act[i] = "A" + to_string(i);
            s[i] = i;
            f[i] = i + 2;
        }

        // Measure execution time
        auto start = high_resolution_clock::now();
        activitySelection(act, s, f);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        file << n << "," << duration.count() << "\n";
    }

    file.close();
    cout << "CSV file generated successfully\n";
    return 0;
}