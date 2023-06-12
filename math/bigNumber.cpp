#include <bits/stdc++.h>
using namespace std;

string multiply(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<int> res(n + m);
    int x, y;
    for (int i = n - 1; i >= 0; i--) {
        x = a[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            y = b[j] - '0';
            res[i + j + 1] += x * y;
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }
    int i = 0;
    while (i < res.size() && res[i] == 0) {
        i++;
    }
    if (i == res.size()) {
        return "0";
    }
    string ans;
    while (i < res.size()) {
        ans += res[i++] + '0';
    }
    return ans;
}

string divide(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    if (n < m || (n == m && a < b))
        return "0";
    string ans;
    string r = a.substr(0, m);
    for (int i = m; i <= n; i++) {
        int x = 0, y = 0;
        while (r.size() > 0 && r[0] == '0') r = r.substr(1);
        if (r.size() > 0) {
            x = stoi(r);
        }
        y = stoi(b);
        int q = x / y;
        ans += to_string(q);
        r = to_string(x % y);
        if (i < n) {
            r += a[i];
        }
    }
    while (ans.size() > 0 && ans[0] == '0') {
        ans = ans.substr(1);
    }
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}