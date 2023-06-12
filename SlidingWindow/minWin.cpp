#include <bits/stdc++.h>
using namespace std;

// 含有子序列（有序）的最短字符串
string minWindow(string s, string t) {
    int m = s.size();
    int n = t.size();
    int left = 0, right = 0;
    int begin = 0;
    int j = 0;
    int minLen = INT_MAX;
    while (right < m) {
        if (s[right] == t[j]) {
            j++;
            if (j == n) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    j = 0;
                    right = left;
                    begin = left;
                    left++;
                }
            }
        }
        right++;
    }
    return minLen == INT_MAX ? "" : s.substr(begin, minLen);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}