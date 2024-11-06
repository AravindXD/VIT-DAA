#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void find_all_lcs(const string &s1, const string &s2, int m, int n, 
                  const vector<vector<int>> &dp, string lcs, set<string> &lcs_set) {
    if (m == 0 || n == 0) {
        reverse(lcs.begin(), lcs.end());
        lcs_set.insert(lcs);
        return;
    }

    if (s1[m - 1] == s2[n - 1]) {
        lcs.push_back(s1[m - 1]);
        find_all_lcs(s1, s2, m - 1, n - 1, dp, lcs, lcs_set);
    } else {
        if (dp[m - 1][n] >= dp[m][n - 1])
            find_all_lcs(s1, s2, m - 1, n, dp, lcs, lcs_set);
        if (dp[m][n - 1] >= dp[m - 1][n])
            find_all_lcs(s1, s2, m, n - 1, dp, lcs, lcs_set);
    }
}

int lcs_length(const string &s1, const string &s2, vector<vector<int>> &dp) {
    int m = s1.size();
    int n = s2.size();

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

string generate_string(int length, int variety) {
    string result;
    for(int i = 0; i < length; i++) {
        result += char('A' + (i % variety));  // Create string with variety different characters
    }
    return result;
}

int main() {
    ofstream file("lcs_times.csv");
    file << "m,n,LCS Time (microseconds)\n";

    // Test with larger range and more varied strings
    for (int m = 5; m <= 15; m += 2) {
        for (int n = m + 2; n <= 20; n += 2) {
            // Create strings with more varied characters to generate multiple LCS
            string s1 = generate_string(m, 3);  // Use 3 different characters
            string s2 = generate_string(n, 3);  // Use 3 different characters

            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            
            // Run multiple times and take average
            const int runs = 5;
            long long total_duration = 0;
            
            for (int run = 0; run < runs; run++) {
                auto start = high_resolution_clock::now();
                int lcs_len = lcs_length(s1, s2, dp);
                set<string> lcs_set;
                find_all_lcs(s1, s2, m, n, dp, "", lcs_set);
                auto stop = high_resolution_clock::now();
                total_duration += duration_cast<microseconds>(stop - start).count();
            }

            long long avg_duration = total_duration / runs;
            file << m << "," << n << "," << avg_duration << "\n";
        }
    }

    file.close();
    cout << "CSV file generated with LCS computation times." << endl;
    return 0;
}