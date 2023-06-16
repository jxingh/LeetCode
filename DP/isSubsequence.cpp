#include <bits/stdc++.h>
using namespace std;

// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

bool isSubsequence(const string &s, const string &t) {
    int m = s.size(), n = t.size();
    if (m > n) {
        return false;
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m][n] == m;
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << (isSubsequence(s, t) ? "Yes" : "No") << endl;
    return 0;
}