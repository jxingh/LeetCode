#include <bits/stdc++.h>
using namespace std;

// 含有所有字符的最短字符串
string minWindow(string s, string t) {
    if (s.size() < t.size())
        return "";
    unordered_map<char, int> need, cur;
    for (char &c : t) {
        need[c]++;
    }
    int left = 0, right = 0;
    int size = 0, start = 0;
    int minLen = INT_MAX;
    while (right < s.size()) {
        char c = s[right++];
        if (need.count(c) != 0) {
            cur[c]++;
            if (cur[c] == need[c]) {
                size++;
            }
        }
        while (size == need.size()) {

            start = left;
            char c = s[left++];
            if (need.count(c) != 0) {
                if (cur[c] == need[c]) {
                    size--;
                }
                cur[c]--;
            }
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}