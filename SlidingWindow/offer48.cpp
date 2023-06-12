#include <bits/stdc++.h>
using namespace std;

// 最长不含重复字符的子字符串
int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int maxLen = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
        while (set.find(s[right]) != set.end()) {
            set.erase(s[left++]);
        }
        set.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}