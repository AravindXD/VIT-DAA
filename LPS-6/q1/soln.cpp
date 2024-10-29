#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int lcs_length(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return curr[n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int lcs_len = lcs_length(s1, s2);
    cout << lcs_len << endl;

    return 0;
}